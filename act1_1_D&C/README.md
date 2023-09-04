# Activity 1.1 - Divide and Conquer Algorithms

# Sorting Algorithms: Merge Sort & Quick Sort

## Overview

This codebase provides an implementation of two of the most prominent divide and conquer sorting algorithms: Merge Sort and Quick Sort. The purpose is to efficiently sort arrays of integers.

## Author Information

- **Author**: Pablo Banzo Prida
- **Date**: 03/09/2023
- **Course**: TC2038 (ITESM)
- **Professor**: Víctor Manuel de la Cueva Hernández

## Data.txt Example

The program requires a `data.txt` file in the working directory containing integers to be sorted. The first line of this file should represent the number of integers, and subsequent lines should have the integers themselves.

For instance, a sample `data.txt` may look like:

```
5
34
12
78
56
23
```

This example signifies that there are 5 integers to be sorted, listed in the subsequent lines.

## Compilation

To compile the program, run the command:

```bash
g++ ordena.cpp -o ordena
```

Then, to run the program, execute the command:

```bash
./ordena
```

## Testing

### Test Helper Class

The `SortTester` class located in "tests/sort_tester.h" is a test helper class designed to assess the correctness of the implemented algorithms.

### Running Tests

To initiate tests, simply add the `SortTester::runTests();` line within the `main()` function. This will trigger a sequence of tests.

On successful test execution, a confirmation message will be shown. In the event of test failure, it will display details about the mismatch between the expected and actual outcomes.

To add new tests, simply add a new `SortTester::runTest()` call within the `SortTester::runTests()` function in "tests/sort_tester.cpp".

To compile the program (considering tests), run the command:

```bash
g++ -std=c++11 'tests/sort_tester.cpp' ordena.cpp -o ordena
```

## Features

- **Data Input**: There's a helper function (`readData()` or its alias `leeDatos()`) which reads integers from a file to form the array.

  Example execution:

  ```cpp
  readData("data.txt");
  ```

- **Output Display**: The `printData()` function (or its alias `imprimeDatos()`) can be used to display the contents of an array (vector) of integers.
  Example execution:
  ```cpp
  printData(arr);
  ```
- **Merge Sort**: The `mergeSort()` function implements the Merge Sort algorithm and sorts the given array (vector) in ascending order.
  Example execution:

  ```cpp
  mergeSort(arr);
  ```

- **Quick Sort**: The `quickSort()` function implements the Quick Sort algorithm and sorts the given array (vector) in ascending order.
  Example execution:
  ```cpp
  quickSort(arr);
  ```
