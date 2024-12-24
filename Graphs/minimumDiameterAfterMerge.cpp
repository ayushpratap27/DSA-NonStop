#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define ll int64_t
using namespace std;

int minimumDiameterAfterMerge(vector<vector<int>> &edges1,
                              vector<vector<int>> &edges2)
{
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    vector<vector<int>> adjList1 = buildAdjList(n, edges1);
    vector<vector<int>> adjList2 = buildAdjList(m, edges2);

    int diameter1 = findDiameter(n, adjList1);
    int diameter2 = findDiameter(m, adjList2);

    int combinedDiameter = ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

    return max({diameter1, diameter2, combinedDiameter});
}


vector<vector<int>> buildAdjList(int size, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(size);
    for (auto edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    return adjList;
}

int findDiameter(int n, vector<vector<int>> &adjList)
{
    auto [farthestNode, _] = findFarthestNode(n, adjList, 0);

    auto [_, diameter] = findFarthestNode(n, adjList, farthestNode);
    return diameter;
}


pair<int, int> findFarthestNode(int n, vector<vector<int>> &adjList,
                                int sourceNode)
{
    queue<int> nodesQueue;
    vector<bool> visited(n, false);
    nodesQueue.push(sourceNode);
    visited[sourceNode] = true;

    int maximumDistance = 0, farthestNode = sourceNode;

    while (!nodesQueue.empty())
    {
        int size = nodesQueue.size();
        for (int i = 0; i < size; ++i)
        {
            int currentNode = nodesQueue.front();
            nodesQueue.pop();
            farthestNode = currentNode;

            for (int neighbor : adjList[currentNode])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    nodesQueue.push(neighbor);
                }
            }
        }
        if (!nodesQueue.empty())
            maximumDistance++;
    }
    return {farthestNode, maximumDistance};
}
