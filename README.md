# c_piscine_tester

Tester for assignments in 42 c piscine

## Table of Contents

- [Project Name](#c_piscine_tester)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Features](#features)
  - [Getting Started](#getting-started)
    - [Installation](#installation)
  	- [Usage](#Usage)
  - [Linkage](#linkage)

## Introduction

This C++ tool tests C files for assignments in the C piscine. It compiles the test files, creates a temporary main file if needed, and runs the tests with specified command-line arguments (argv). The program reads and compares the output against expected results.

## Features

- Comprehensive test cases covering edge scenarios.
- Flags for different tester display modes.
- User-friendly UI to pinpoint test case failures.

## Getting Started

### Installation

Paste the following command into your terminal

- `git clone git@github.com:stanX19/c_piscine_tester.git c_piscine_tester`
- `cd c_piscine_tester`

# Usage

1. Cd into the the tester you are interested in, e.g. "C00tester"

	- `cd C00tester`

2. compile the binary executable

	- `make`

3. run the binary executable

	- `./C00tester -h`

4. you will see a usage message, take time to read though it, it is not an error.

	You are well set, you can now test your project :D

	- `./C00tester ~/Desktop/C00 -fd`

To run another project, repeat from [step 1](Usage)

## linkage

CUnitTest: https://github.com/stanX19/CTest
