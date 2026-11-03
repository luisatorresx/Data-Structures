# Data Structures in C++

[![build](https://github.com/luisatorresx/Data-Structures/actions/workflows/build.yml/badge.svg)](https://github.com/luisatorresx/Data-Structures/actions/workflows/build.yml)

Classic data structures and algorithms implemented from scratch in C++: linked lists, stacks, queues, hash tables and external sorting. No STL containers are used for the structures themselves; every node, pointer and file pass is written by hand.

Built for the Data Structures course of the Computer Engineering degree at Universidad de Oriente (Venezuela).

> Code comments and program output are in Spanish, as originally submitted.

## Contents

| # | Project | Data structure | What it does |
|---|---|---|---|
| 01 | [Big-number addition](01-circular-list-big-number-sum) | Circular doubly linked list | Adds two 30–50 digit integers digit by digit, with carry |
| 02 | [Doubly linked list](02-doubly-linked-list) | Generic doubly linked list (template) | Insert, remove, and traverse forwards and backwards |
| 03 | [Infix to postfix](03-infix-to-postfix-stack) | Generic linked stack (template) | Converts `a*(b+c)` to `abc+*` with operator precedence |
| 04 | [Palindrome check](04-palindrome-queue-and-stack) | Circular array queue + linked stack | Checks whether a number reads the same in both directions |
| 05 | [Hash table](05-hash-table-chaining) | Hash table with separate chaining | Stores 1,000 random integers and finds the longest chain |
| 06 | [Straight merge sort](06-straight-merge-sort) | External sort with 2 auxiliary files | Sorts a file of integers that is not loaded into memory |
| 07 | [Balanced multiway merge sort](07-balanced-multiway-merge-sort) | External sort with 6 auxiliary files | Faster external sort using natural runs |

## Build and run

You need a C++17 compiler (`g++` or `clang++`) and `make`.

```bash
make                                   # build every program into build/
make run P=03-infix-to-postfix-stack   # build and run one program
make test                              # build everything and run the tests
```

Without `make`, compile any program directly:

```bash
g++ -std=c++17 -o infix 03-infix-to-postfix-stack/main.cpp
./infix
```

## Tests

`make test` runs every program with sample input and checks the output. GitHub Actions runs the build and tests on Linux and macOS for every push.

## Concepts practiced

- Pointer-based structures: singly, doubly and circular linked lists
- Class templates for generic containers (`PilaT<T>`, `ListaDoble<T>`, `Cola<T>`)
- Manual memory management with `new` and `delete`
- Stack and queue applications: expression parsing and palindrome detection
- Hashing with separate chaining and load factor
- External sorting with file streams (straight merge and balanced multiway merge)
