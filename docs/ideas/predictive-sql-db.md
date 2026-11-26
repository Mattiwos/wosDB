# wosDB: A Tiny SQL Database with Predictive Prefetching

## Problem Statement
How might we build a small, crash-safe SQL database whose buffer pool predicts upcoming page reads, and prove with benchmarks that prediction beats a plain LRU cache?

## Recommended Direction
Build bottom-up: pager → buffer pool (with access-trace logging) → B-tree → WAL + recovery → SQL subset. Every layer is testable alone, and crash safety is designed in rather than bolted on.

The prediction work runs in parallel as an offline simulator that replays the database's own access traces. It compares LRU, ARC and a Markov-chain prefetcher before anything is wired into the real buffer pool. Only a policy that wins in simulation gets implemented.

Benchmark against SQLite (same embedded scope), not Postgres. The goal is learning plus measured numbers, not production use.

## Key Assumptions to Validate
- [ ] Realistic workloads have predictable access patterns. Test: run the simulator on a correlated workload (user→orders style) vs. uniform random. Prediction should only win on the first.
- [ ] Prefetching gains outweigh wasted I/O. Test: track hit rate, prefetch accuracy and wasted reads together.
- [ ] Crash safety actually works. Test: a harness that kill -9s the process mid-write in a loop and verifies the DB after every restart.
- [ ] Milestones are small enough for a few hours/week. Test: each one finished within ~4 weeks. If not, cut scope.

## MVP Scope
In:
1. Pager: fixed 4 KB pages in one file
2. Buffer pool with LRU eviction, a configurable size and an access-trace log
3. B-tree table storage (single integer primary key)
4. WAL + recovery, verified by the kill -9 harness
5. SQL subset: CREATE TABLE, INSERT, SELECT with WHERE pk = / BETWEEN, via a REPL
6. Offline prefetch simulator over the recorded traces
7. Benchmark: wosDB vs. SQLite, and LRU vs. the predictive policy

Out: everything below.

## Not Doing (and Why)
- Document / hybrid DB: splits focus; SQL is the point
- Network server + custom wire protocol + HTTP: an embedded REPL is enough to learn and benchmark; a server adds nothing to the core question
- JOINs and a cost-based planner: huge scope; single-table queries show prefetching fine
- Concurrency / MVCC / transactions beyond the WAL: a single writer keeps recovery understandable
- ML-model prediction: a Markov baseline has to fail first before an ML model is justified
- Compression, auth, regex search: README goals that don't serve this direction

## Decisions
- **Fresh start in this repo.** The old KV implementation was removed and is preserved on branch `archive/kv-v1`.
- **Language: C++20, with no Boost and no third-party dependencies in the engine.** On-disk formats are plain fixed-layout structs with explicit byte (de)serialization.
  - RAII page guards make "forgot to unpin a page" bugs impossible by construction. That's the classic buffer-pool bug, and in C it's easy to make.
  - The standard library supplies the page table and LRU lists (`unordered_map`, `list`), so time goes to the database instead of writing a hash table first. This matters at a few hours a week.
  - CMU 15-445 (BusTub) is written in C++ and covers the same path: buffer pool → B+tree → recovery. It's a ready-made study companion.
  - C (the SQLite route) would also work, but costs more time on infrastructure with no extra database learning.

## Open Questions
- Which benchmark workload has realistic correlation? Write a small synthetic generator, or adapt a TPC-C-like pattern?
- Predict per page, or per (table, key range)? The simulator should decide.
