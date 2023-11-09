#ifndef DATA_STRUCTS_HPP
#define DATA_STRUCTS_HPP

#include <vector>
#include <list>

using namespace std;

// Graph data structure
struct Graph
{
    vector<vector<int>> matrix;
    vector<list<pair<int, int>>> adj_list;
};

#endif