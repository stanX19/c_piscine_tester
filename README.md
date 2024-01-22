# c_piscine_tester

Tester for assignments in 42 c piscine

## Introduction

This C++ tool tests C files for assignments in the C piscine. It compiles the test files, creates a temporary main file if needed, and runs the tests with specified command-line arguments (argv). The program reads and compares the output against expected results.

## Features

- Comprehensive test cases covering edge scenarios.
- Flags for different tester display modes.
- User-friendly UI to pinpoint test case failures.

## Getting Started

### Installation

To get started, run the following commands in your terminal:

```bash
git clone git@github.com:stanX19/c_piscine_tester.git c_piscine_tester
cd c_piscine_tester
```

### Usage

1. Cd into the the tester you are interested in, e.g. "C00tester"

```bash
cd C00tester
```

2. compile the binary executable

```bash
make
```

3. run the binary executable

```bash
./C00tester -h
```

4. You will see a usage message; take the time to read through it; it is not an error.

You are now ready to test your project. For example, to test a project in the "~/Desktop/C00" directory with additional flags, you can use:

```bash
./C00tester ~/Desktop/C00 -fd
```

To run another tester, repeat from [step 1](#Usage)

## linkage

CUnitTest: https://github.com/stanX19/CTest
