#include<bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while (!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        if (r == destination.first && c == destination.second){
            return dis;
        }

        for (int i = 0; i < 4; i++){
            int newR = r + delRow[i];
            int newC = c + delCol[i];

            if (newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == 1 && dis + 1 < dist[newR][newC]){
                dist[newR][newC] = 1 + dis;

                q.push({1 + dis, {newR, newC}});
            }
        }
    }

    return -1;
}

//  For all the 8 directions
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0)
        return -1;
    int m = grid[0].size();

    if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
        return -1;

    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 1;
    q.push({1, {0, 0}});
    int delRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int delCol[] = {0, 1, 1, 1, 0, -1, -1, -1};

    while (!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        if (r == n - 1 && c == m - 1){
            return dis;
        }

        for (int i = 0; i < 8; i++){
            int newR = r + delRow[i];
            int newC = c + delCol[i];

            if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                grid[newR][newC] == 0 && dis + 1 < dist[newR][newC]){
                dist[newR][newC] = 1 + dis;
                q.push({1 + dis, {newR, newC}});
            }
        }
    }

    return -1;
}