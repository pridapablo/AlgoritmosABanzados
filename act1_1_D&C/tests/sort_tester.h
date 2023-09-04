// For testing purposes only.
// This file is not part of the project.
#ifndef SORT_TESTER_H
#define SORT_TESTER_H

#include <iostream>
#include <vector>

std::vector<int> mergeSort(const std::vector<int> &data);
std::vector<int> quickSort(const std::vector<int> &data);

class SortTester
{
public:
    static void runTests();

private:
    static void printData(const std::vector<int> &data);
    static bool checkResult(const std::vector<int> &actual, const std::vector<int> &expected);
    static void runTest(const std::vector<int> &data, const std::vector<int> &expected);
};

#endif
