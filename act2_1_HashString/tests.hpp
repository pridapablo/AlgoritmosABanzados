// tests.hpp
#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "hashing.hpp"
#include "operations.hpp"

using namespace std;

/*
Function to run the test cases.
*/
void runTestCases()
{
    vector<pair<string, int>> testCases = {
        {"file_empty.txt", 16},
        {"file_small.txt", 16},
        {"file_big.txt", 64},
        {"file_multipleOfN.txt", 32}};

    for (auto &testCase : testCases)
    {
        string content = readFiles(testCase.first);
        if (content.empty())
        {
            cout << "Error reading test file: " << testCase.first << endl;
            continue;
        }

        if (!validateN(testCase.second))
        {
            cout << "Invalid n in test case: " << testCase.second << endl;
            continue;
        }

        string hash = hashString(content, testCase.second);
        cout << "Hash for file " << testCase.first << " with n = " << testCase.second << " is: " << hash << endl;
    }
}

#endif