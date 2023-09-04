// For testing purposes only.
// This file is not part of the project.
#include "sort_tester.h"

void SortTester::printData(const std::vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

bool SortTester::checkResult(const std::vector<int> &actual, const std::vector<int> &expected)
{
    return actual == expected;
}

void SortTester::runTest(const std::vector<int> &data, const std::vector<int> &expected)
{
    std::cout << "Original: ";
    printData(data);

    std::vector<int> resultMerge = mergeSort(data);
    std::vector<int> resultQuick = quickSort(data);

    std::cout << "MergeSort: ";
    printData(resultMerge);
    std::cout << "Correct? " << (checkResult(resultMerge, expected) ? "YES" : "NO") << std::endl;

    std::cout << "QuickSort: ";
    printData(resultQuick);
    std::cout << "Correct? " << (checkResult(resultQuick, expected) ? "YES" : "NO") << std::endl;

    std::cout << "------------------------------------------------" << std::endl;
}

void SortTester::runTests()
{
    runTest({5, 4, 3, 2, 1}, {1, 2, 3, 4, 5});                                         // reverse sorted
    runTest({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});                                         // sorted
    runTest({3, 3, 3, 3, 3}, {3, 3, 3, 3, 3});                                         // all identical
    runTest({}, {});                                                                   // empty
    runTest({5}, {5});                                                                 // single element
    runTest({1, 3, 2, 5, 4}, {1, 2, 3, 4, 5});                                         // shuffled
    runTest({1, 3, 2, 5, 4, 5}, {1, 2, 3, 4, 5, 5});                                   // duplicated values
    runTest({-1, 0, 1, -2, 2}, {-2, -1, 0, 1, 2});                                     // negative values
    runTest({9, 7, 5, 3, 1, 2, 4, 6, 8, 10}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});         // alternating sequence
    runTest({-5, -4, -3, -2, -1, 0, 1, 2, 3, 4}, {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4}); // negative to positive
    runTest({1, 1, 2, 2, 3, 3, 4, 4, 5, 5}, {1, 1, 2, 2, 3, 3, 4, 4, 5, 5});           // paired duplicates
    runTest({10, 8, 10, 8, 6, 4, 6, 4, 2, 0}, {0, 2, 4, 4, 6, 6, 8, 8, 10, 10});       // duplicated decreasing values
    runTest({0}, {0});                                                                 // zero as single element
    runTest({-1, -1, -1, 0, 0, 0, 1, 1, 1}, {-1, -1, -1, 0, 0, 0, 1, 1, 1});           // triplicates mixed
}
