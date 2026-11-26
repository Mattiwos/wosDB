# Handoff: 2026-11-26

Status of wosDB at the end of the 2026-11-26 session, for whoever (you or an agent) picks it up next.

## Where things stand

wosDB was restarted from scratch as a **tiny, crash-safe SQL database in C++20 whose buffer pool predicts upcoming page reads**, as a learning project. The repo contains an empty but working build skeleton. No database code has been written yet.

- Direction and scope: [ideas/predictive-sql-db.md](ideas/predictive-sql-db.md)
- Milestones, time estimates and reading: [plan.md](plan.md)

## What was done this session

1. **Refined the idea** (idea-refine skill). The original idea was "Postgres-like DB that predicts future fetches and caches them". It was narrowed to a bottom-up storage engine plus an offline prefetch simulator, benchmarked against SQLite.
   - **Who it's for:** you, for learning.
   - **Success:** it survives crashes and is benchmarked.
   - **Time budget:** a few hours a week.
2. **Removed the old implementation.** That was the key/value store with Boost serialization, the socket server, the custom message protocol, the committed binaries and the CMake build files left in `wosDB-tests/`. **All of it is preserved on branch `archive/kv-v1`.** `.Notes/`, `LICENSE`, `.clang-format` and `.gitignore` were kept. `README.md` was rewritten.
3. **Chose the language: C++20, with no Boost and no third-party dependencies in the engine.**
   - RAII page guards, standard containers for the buffer pool, and CMU 15-445/BusTub is in C++. Full reasoning is under "Decisions" in the ideas doc.
   - Clang is the compiler.
4. **Installed the toolchain.** Added `clang`, `clang-tools`, `cmake`, `ninja` and `lldb` to `~/nix-config/modules/packages.nix`, then rebuilt the system. Verified versions: clang 21.1.8, cmake 4.4.4, ninja 1.13.2.
5. **Set up the build skeleton.**
   - `CMakeLists.txt`: C++20, strict warnings on our own targets, and a `wosdb` library. Currently it holds only `version()`.
   - `CMakePresets.json`: a `debug` preset using Clang and Ninja, output in `build/debug`.
   - `tests/`: GoogleTest 1.17.0 downloaded at configure time with a pinned SHA256, used only by tests, plus one placeholder test.
   - `.clangd`: points clangd at `build/debug/compile_commands.json`.
   - Verified: `cmake --workflow --preset debug` configures, builds and passes 1/1 tests, with zero warnings from our code.
6. **Wrote the plan** (`docs/plan.md`): 8 milestones, about 141–194 hours, roughly 9–12 months at 4 h/week.

## How to build and test

```bash
cmake --workflow --preset debug              # configure + build + test
cmake --build --preset debug && ctest --preset debug   # after the first time
```

One expected warning appears while GoogleTest itself compiles (`-Wcharacter-conversion`, new in Clang 21). It comes from GoogleTest's code, not ours, and is safe to ignore.

## Repo layout

```
CMakeLists.txt  CMakePresets.json  .clangd  .clang-format
include/wosdb/  # public headers
src/            # engine
tests/          # GoogleTest tests
docs/           # ideas/, plan.md, HANDOFF.md
.Notes/         # personal notes and progress blog (from before)
```

## Next action

**Start M1, the pager** (see `docs/plan.md`). Write the tests first: write then read the same bytes, data surviving reopen, page allocation, out-of-range IDs, and a bad magic number. Then implement `Pager` using `pread`/`pwrite`. The placeholder `version()` can stay or go when real code arrives.

## Open questions (none block M1)

- Which correlated workload is realistic enough for the M3 simulator: a synthetic user→orders generator, or something modeled on TPC-C?
- Predict at page granularity or at (table, key range) granularity? M3 should answer this.
- Run code-quality tools (clang-tidy, sanitizers) in the build? Deliberately not added yet. Consider turning on the address and undefined-behavior sanitizers in a preset before M2, since pointer and pin-count bugs show up there.

## Environment notes

- NixOS. Toolchain packages live in `~/nix-config/modules/packages.nix` under `extendedDevPackages`, in the `# wosDB (C++20)` block. Rebuild the system after editing.
- The first configure downloads GoogleTest from GitHub, so it needs network access.
