# Linked List
Simple C doubly linked list with sorted insert.

## Overview
This project implements a simple doubly linked list in C with sorted insert functionality. The linked list supports basic operations such as creating nodes, inserting nodes in sorted order, printing the list, and freeing the list.

## Files
- `linkedList.c`: Contains the implementation of the linked list functions. This file includes all the necessary functions to manage the linked list, such as creating a new node, inserting a node in sorted order, printing the list, and freeing the allocated memory.
- `linkedList.h`: Header file for the linked list functions. It provides the function prototypes and necessary data structures used in `linkedList.c`.
- `main.c`: Example usage of the linked list. This file demonstrates how to use the linked list functions by creating a list, inserting nodes, and printing the list.
- `test/test_linkedList.c`: Unit tests for the linked list functions. This file contains test cases to verify the correctness of the linked list implementation.
- `test/unity.c`: Unity test framework source file. Unity is a lightweight unit testing framework for C, which is used to run the tests in `test/test_linkedList.c`.
- `Makefile`: Build and test automation. The Makefile includes targets for building the project, running the tests, and cleaning up build artifacts.

## Prerequisites
Before you can build and run this project, you need to have the following tools installed on your system:
- GCC (GNU Compiler Collection): A compiler system supporting various programming languages, including C.
- Make: A build automation tool that automatically builds executable programs and libraries from source code.

## Building the Project
To build the project, open a terminal and navigate to the project directory. Then, run the following command:
```sh
make build
```
This command will compile the source files and create an executable named `linkedList` in the `build` directory. The `Makefile` handles all the compilation details, so you don't have to worry about the individual compiler commands.

## Running the Example
After building the project, you can run the example provided in `main.c` by executing the following command:
```sh
./build/linkedList
```
This will run the executable and demonstrate the functionality of the linked list, including creating nodes, inserting them in sorted order, and printing the list.

## Running the Tests
To ensure that the linked list implementation is correct, you can run the unit tests. Use the following command to compile and run the tests:
```sh
make test
```
This command will compile the test files and run the tests using the Unity test framework. The test results will be displayed in the terminal, indicating whether the tests passed or failed.

## Cleaning Up
To remove the build artifacts and clean up the project directory, run the following command:
```sh
make clean
```
This will delete the compiled executable and object files. If you also want to clean the test build artifacts, run:
```sh
make clean_test
```
This command will remove the compiled test executables and object files, ensuring that your project directory is clean.

## Author
- Henrique Guimaraes