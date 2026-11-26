# wosDB Build Plan

The direction, scope and "Not Doing" list are in [ideas/predictive-sql-db.md](ideas/predictive-sql-db.md). This file covers the order of work, the goal of each step, time estimates and learning material.

## Assumptions behind the estimates

- About **4 hours a week**. Estimates are focused hours, including reading and debugging. Weeks assume that pace.
- Estimates are ranges because first-time database work is hard to predict. The B+tree and WAL are where overruns usually happen.
- Every milestone ends with passing tests and a commit. If one runs past its upper estimate, cut scope instead of continuing to grind.

## Summary

| # | Milestone | Hours | Weeks @ 4 h | Cumulative weeks |
|---|-----------|-------|-------------|------------------|
| 1 | Pager | 8–12 | 2–3 | 2–3 |
| 2 | Buffer pool + access trace | 15–20 | 4–5 | 6–8 |
| 3 | Prefetch simulator (**decision gate**) | 15–20 | 4–5 | 10–13 |
| 4 | WAL + crash recovery | 20–30 | 5–8 | 15–21 |
| 5 | Slotted pages + row format | 8–12 | 2–3 | 17–24 |
| 6 | B+tree | 30–40 | 8–10 | 25–34 |
| 7 | SQL subset + catalog + REPL | 30–40 | 8–10 | 33–44 |
| 8 | Live prefetching + benchmarks | 15–20 | 4–5 | 37–49 |
| | **Total** | **~141–194 h** | | **~9–12 months** |

### Why this order

- **Simulator early (M3).** It tests the riskiest assumption, that access patterns are predictable, about 3 months in instead of 10. Its result also decides whether the buffer pool needs a prefetch hook.
- **WAL before the B+tree (M4).** The WAL logs whole page images at the buffer-pool layer, so anything built on top, including the B+tree and the catalog, is crash-safe automatically. Adding logging to a finished B+tree later is much harder.

---

## M1: Pager (8–12 h)

**Goal:** Read and write fixed 4 KB pages in a single file by page ID. Learn how a database talks to the file system and what `fsync` actually guarantees.

**Deliverables**
- `PageId` type. Page 0 is a file header holding a magic number, format version and page count.
- `Pager::open(path)`, `read_page(id, span)`, `write_page(id, span)`, `allocate_page()` and `sync()`, using `pread`/`pwrite`.
- On-disk integers in a fixed byte order, written with explicit encode/decode helpers (no struct casting).

**Done when:** tests pass for writing then reading the same bytes, data surviving close and reopen, allocating many pages, rejecting out-of-range IDs, and rejecting a file with a bad magic number.

**Learning material**
- CMU 15-445/645 lectures on *Database Storage* (both parts). Course site: https://15445.courses.cs.cmu.edu/, with lecture videos on the CMU Database Group YouTube channel.
- *Database Internals*, Alex Petrov (O'Reilly, 2019): Ch. 3 "File Formats".
- `man 2 pread`, `man 2 pwrite`, `man 2 fsync`.
- Dan Luu, "Files are hard": https://danluu.com/file-consistency/

## M2: Buffer pool + access trace (15–20 h)

**Goal:** Keep a fixed number of pages in memory, evict with LRU, and log every page access. This is the core of the project, and everything else depends on it.

**Deliverables**
- Frames, a page table (`unordered_map<PageId, FrameId>`), pin counts and dirty flags.
- A `Replacer` interface with an `LruReplacer` implementation. It's the same interface the simulator and the predictive policy will use later.
- A `PageGuard` object that unpins automatically when it goes out of scope, and can be moved but not copied.
- A trace log: a binary file of (sequence number, page ID, read or write, hit or miss).

**Done when:** tests cover eviction order, never evicting pinned pages, dirty pages written back on eviction, returning an error when everything is pinned, and the trace matching the expected access sequence.

**Learning material**
- CMU 15-445 lecture on *Buffer Pools*, plus BusTub Project 1 (Buffer Pool Manager) as a reference design: https://github.com/cmu-db/bustub
- *The Internals of PostgreSQL*, Ch. 8 "Buffer Manager": https://www.interdb.jp/pg/
- *Database Internals*, Ch. 5 "Buffer Management".

## M3: Prefetch simulator (15–20 h). DECISION GATE

**Goal:** Find out cheaply whether prediction beats good non-predictive caching before building it into the database.

**Deliverables**
- A workload generator with three patterns: uniform random, Zipfian (a few hot keys get most accesses) and correlated ("read user X, then their orders"). It writes the M2 trace format.
- A simulator that replays a trace against a policy and buffer size. Policies: LRU, ARC, and a first-order Markov prefetcher ("after page A, page B usually follows").
- Metrics: hit rate, prefetch accuracy and wasted prefetches, at several buffer sizes.

**Decision gate:** if the Markov prefetcher clearly beats ARC on the correlated workload (and doesn't lose badly on uniform), keep the plan. If it doesn't, rethink before M8. Options would be predicting at the query level instead of the page level, or dropping prediction and keeping the database.

**Learning material**
- Megiddo & Modha, "ARC: A Self-Tuning, Low Overhead Replacement Cache", FAST 2003.
- O'Neil, O'Neil & Weikum, "The LRU-K Page Replacement Algorithm for Database Disk Buffering", SIGMOD 1993.
- Joseph & Grunwald, "Prefetching using Markov Predictors", ISCA 1997.
- Cooper et al., "Benchmarking Cloud Serving Systems with YCSB", SoCC 2010, for how to generate Zipfian workloads.
- Optional, to read only: Hashemi et al., "Learning Memory Access Patterns", ICML 2018 (machine-learning prefetching).

## M4: WAL + crash recovery (20–30 h)

**Goal:** A `kill -9` at any moment never loses committed data or leaves the file corrupt. This is the "survives crashes" criterion.

**Deliverables**
- A redo-only log of whole page images. On commit, write the full image of each dirty page, then a commit record, then `fsync` the log, and only then report success.
- No-steal: dirty pages from an uncommitted batch are never written to the data file.
- A CRC32 checksum on every log record, so a half-written record at the end of the log is detected and ignored.
- Recovery on open: replay committed batches and ignore incomplete ones. Checkpoint: flush and fsync the data file, then truncate the log.
- **Crash harness:** a script that repeatedly runs a writer process, `kill -9`s it at a random moment, reopens the database and checks that every committed write is there.

**Done when:** the crash harness runs 1,000+ kill cycles with zero lost commits and zero corruption.

**Learning material**
- SQLite, "Atomic Commit In SQLite": https://www.sqlite.org/atomiccommit.html (the best single read for this step).
- SQLite, "Write-Ahead Logging": https://www.sqlite.org/wal.html
- *The Internals of PostgreSQL*, Ch. 9 "Write Ahead Logging": https://www.interdb.jp/pg/
- Pillai et al., "All File Systems Are Not Created Equal", OSDI 2014 (what `fsync` really guarantees).
- CMU 15-445 lectures on *Logging* and *Recovery*.
- Background only, not to implement: Mohan et al., "ARIES", ACM TODS 1992.

## M5: Slotted pages + row format (8–12 h)

**Goal:** Store variable-length rows inside a page. B+tree nodes and table rows both build on this.

**Deliverables**
- A slotted page layout: a header and a slot array growing from the front, row data growing from the back, with insert, delete and compaction.
- Row encoding for INTEGER and TEXT columns.

**Done when:** tests cover filling a page until it's full, deleting and reusing space, compaction keeping all rows intact, and rows decoding back to the same values.

**Learning material**
- CMU 15-445 lecture on *Storage Models & Tuple Layout*.
- SQLite Database File Format, the "B-tree Pages" and "Record Format" sections: https://www.sqlite.org/fileformat.html
- *Database Internals*, Ch. 3, the "Slotted Pages" section.

## M6: B+tree (30–40 h). The biggest step

**Goal:** Table storage keyed by an integer primary key, with point lookups and range scans.

**Deliverables**
- Search, insert with leaf and inner-node splits, and range scans that follow sibling links between leaves.
- Delete without merging nodes (lazy delete). Real merging can come later if ever needed.

**Done when:** a randomized test runs 100k mixed operations against `std::map` and the results always match. The tree's invariants (sorted keys, balanced height, no overfull nodes) are checked after every split, and the crash harness also passes on B+tree workloads.

**Learning material**
- CMU 15-445 lectures on *Tree Indexes* (both parts), plus BusTub's B+tree project.
- *Database Internals*, Ch. 2 "B-Tree Basics" and Ch. 4 "Implementing B-Trees".
- cstack, "Let's Build a Simple Database", Parts 8–14 (a B-tree in C): https://cstack.github.io/db_tutorial/
- Optional deep dive: Graefe, "Modern B-Tree Techniques", Foundations and Trends in Databases, 2011.

## M7: SQL subset + catalog + REPL (30–40 h)

**Goal:** The "it's a SQL database" step: `CREATE TABLE`, `INSERT`, and `SELECT ... WHERE pk = ? / BETWEEN` from an interactive prompt.

**Deliverables**
- A tokenizer, a hand-written recursive-descent parser and a syntax tree.
- A catalog that stores table schemas in the database file itself (a reserved B+tree, as SQLite does).
- An executor with three operations: primary-key lookup, range scan and full scan with a filter.
- A REPL that prints result tables and errors.

**Done when:** golden-file tests (SQL in, expected output stored alongside) cover every statement type and the parser's error messages.

**Learning material**
- *Crafting Interpreters*, Robert Nystrom, chapters "Scanning" and "Parsing Expressions" (free online): https://craftinginterpreters.com/
- SQLite SQL syntax diagrams, as the grammar to copy a subset from: https://www.sqlite.org/lang.html
- CMU 15-445 lectures on *Query Execution* and *Query Processing*.
- Hellerstein, Stonebraker & Hamilton, "Architecture of a Database System", Foundations and Trends in Databases, 2007 (how the pieces fit together).

## M8: Live prefetching + benchmarks (15–20 h)

**Goal:** Plug the winning M3 policy into the real buffer pool and produce the final numbers.

**Deliverables**
- A prefetch hook in the buffer pool: on a miss, ask the predictor for likely next pages and load them if there are free frames. Start synchronous; add a background thread only if measurements show it helps.
- A benchmark harness timed with `std::chrono` that runs the M3 workloads through SQL.
- Results: wosDB with LRU vs. wosDB with prediction vs. SQLite, reporting throughput, p50/p99 latency and buffer hit rate.

**Done when:** a short write-up in `docs/` has the benchmark tables and an honest conclusion, whatever the numbers show.

**Learning material**
- SQLite, "How SQLite Is Tested": https://www.sqlite.org/testing.html (testing and benchmarking discipline).
- Brendan Gregg's material on latency and percentiles: https://www.brendangregg.com/
- Optional: Will Wilson, "Testing Distributed Systems w/ Deterministic Simulation", Strange Loop 2014 (simulation testing in the FoundationDB style).

---

## Books to keep at hand throughout

- **CMU 15-445/645** (Andy Pavlo): the closest thing to a syllabus for this project.
- ***Database Internals***, Alex Petrov: storage engines, B-trees, buffer management, recovery.
- ***The Internals of PostgreSQL***, Hironobu Suzuki (free online): how a real system does each step.
