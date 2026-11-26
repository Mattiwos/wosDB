# wosDB

A tiny, crash-safe SQL database written in C++20, built to learn how databases work. Its buffer pool predicts upcoming page reads and prefetches them, and benchmarks show whether that beats a plain LRU cache.

See [docs/ideas/predictive-sql-db.md](docs/ideas/predictive-sql-db.md) for the plan, scope and what's intentionally out of scope, [docs/plan.md](docs/plan.md) for milestones and learning material, and [docs/HANDOFF.md](docs/HANDOFF.md) for the current status.

## Status

Fresh start. The earlier key/value implementation is preserved on the `archive/kv-v1` branch.

## Building

Requires Clang, CMake (3.25 or newer) and Ninja. To configure, build and run all tests:

```bash
cmake --workflow --preset debug
```

Builds go to `build/debug/`. To rebuild and rerun tests after that, use `cmake --build --preset debug && ctest --preset debug`.

## Roadmap

- [ ] Pager: fixed 4 KB pages in one file
- [ ] Buffer pool: LRU eviction, configurable size, access-trace log
- [ ] B-tree table storage
- [ ] WAL + recovery (verified by a kill -9 harness)
- [ ] SQL subset: `CREATE TABLE`, `INSERT`, `SELECT ... WHERE pk = / BETWEEN` via a REPL
- [ ] Offline prefetch simulator (LRU vs. ARC vs. Markov)
- [ ] Benchmarks vs. SQLite

## License

See [LICENSE](LICENSE).
