# Basic C Programs

A collection of small, well-documented C programs that demonstrate basic to intermediate C programming concepts. This repository is intended for beginners who want working examples of common tasks, and for anyone who wants quick reference programs to study, compile, and run.

## Table of Contents
- [What you'll find here](#what-youll-find-here)
- [Prerequisites](#prerequisites)
- [How to compile & run](#how-to-compile--run)
- [Typical repository structure](#typical-repository-structure)
- [Contributing](#contributing)
- [Code style and guidelines](#code-style-and-guidelines)
- [License](#license)
- [Contact](#contact)

## What you'll find here
This repo contains small, single-purpose C programs that cover topics such as:
- Hello world and basic I/O
- Variables and data types
- Control flow (if/else, switch, loops)
- Functions and recursion
- Arrays and strings
- Pointers and memory basics
- Simple data structures (linked lists, stacks, queues)
- Sorting and searching algorithms
- File I/O examples
- Basic math and utility programs

Each program is intended to be easy to read and compile. Most files include comments explaining the logic and usage.

## Prerequisites
- A C compiler such as `gcc` or `clang`
- (Optional) Make if there are Makefiles included

On Debian/Ubuntu:
sudo apt update && sudo apt install build-essential

On macOS:
Install Xcode Command Line Tools:
xcode-select --install

On Windows:
Use MinGW-w64 or WSL for a POSIX-like environment.

## How to compile & run
Compile a single file:
gcc -o program program.c
./program

Compile with warnings enabled (recommended while learning):
gcc -Wall -Wextra -pedantic -std=c11 -o program program.c

If the repository includes a Makefile, simply run:
make
Then run the produced binary (often `./program` or as described in the specific folder's README).

Examples:
- Compile and run hello.c:
  gcc -o hello hello.c
  ./hello

- Compile multiple sources:
  gcc -o myapp main.c utils.c

## Typical repository structure
(Actual layout may vary)
- basics/
  - hello.c
  - variables.c
- control-flow/
  - if_else.c
  - loops.c
- functions/
  - recursion.c
- arrays-strings/
  - array_sort.c
  - string_reverse.c
- pointers/
  - pointer_intro.c
- data-structures/
  - linked_list.c
- algorithms/
  - bubble_sort.c
  - binary_search.c
- file-io/
  - read_file.c
- utils/
  - common_helpers.h

Each folder may contain its own README describing examples and how to run them.

## Contributing
Contributions are welcome! Suggestions:
1. Fork the repo.
2. Create a feature branch: git checkout -b feature/brief-description
3. Add your program(s) and include comments describing purpose and usage.
4. Make sure code compiles cleanly and run basic tests.
5. Submit a pull request describing your changes.

When adding exercises, prefer:
- Clear file names (e.g., `bubble_sort.c`)
- Short focused examples (one concept per file)
- Comments that explain non-obvious parts
- A short usage comment at top with compile/run instructions

If you find a bug or have an improvement idea, open an issue.

## Code style and guidelines
- Aim for clarity over cleverness.
- Compile with -Wall -Wextra and treat warnings seriously.
- Use meaningful variable and function names.
- Document assumptions and sample input/output in comments.
- Prefer standard C (C99/C11) for portability.

## License
If this repository does not already include a LICENSE file, consider adding one. A permissive option is the MIT License. If you want a different license, add a LICENSE file and update this section.

## Contact
Repository: https://github.com/Sbiswas001/Basic-c-programs
Author / Maintainer: Sbiswas001

If you'd like, I can:
- Create this README.md in the repository,
- Add a sample CONTRIBUTING.md,
- Or generate per-folder READMEs listing contained programs (I can scan the repo first).

Which would you like me to do next?
