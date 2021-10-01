//?https://hack.codingblocks.com/app/contests/1783/1731/problem
#include<bits/stdc++.h>
using namespace std;

queue<pair<int,int>> Q;

bool isValid(int i, int j, int n, int m) {
    if(i >= 0 and i < n and j >= 0 and j < m)
        return true;
    return false;
}

void dfs(vector<vector<int>> &mat, vector<vector<int>> &dist, int i, int j) {
    int n = mat.size();
    int m = mat[0].size();

    if(!isValid(i, j, n, m))
        return;
    if(mat[i][j] == 0)
        return;
    
    mat[i][j] = -1; // Changing to -1 so that we don't add it more than once.
    dist[i][j] = 0;
    Q.push({i, j});

    dfs(mat, dist, i, j + 1);
    dfs(mat, dist, i + 1, j);
    dfs(mat, dist, i, j - 1);
    dfs(mat, dist, i - 1, j);
}

int shortestPath(vector<vector<int>> &mat, vector<vector<int>> &dist) {
    int n = mat.size();
    int m = mat[0].size();

    int mn = INT_MAX;
    vector<int> dir{0, 1, 0, -1, 0};

    while(!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        int x = p.first;
        int y = p.second;

        for(int i = 0; i < 4; i++) {
            int curRow = x + dir[i];
            int curCol = y + dir[i + 1];

            int curDist = dist[x][y] + 1;

            if(isValid(curRow, curCol, n, m) and mat[curRow][curCol] != -1) {
                if(curDist < dist[curRow][curCol]) {
                    dist[curRow][curCol] = curDist;
                    Q.push({curRow, curCol});
                }

                if(mat[curRow][curCol] == 1) {
                    mn = min(mn, dist[x][y]);
                }
            }
        }
    }
    return mn;
}

int shortestBridge(vector<vector<int>> &mat) {
    if(mat.size() == 0)
        return 0;
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1) {
                dfs(mat, dist, i, j);
                // return 1;
                return shortestPath(mat, dist);
            }
        }
    }
    return -1;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    cout << shortestBridge(mat) << endl;
}