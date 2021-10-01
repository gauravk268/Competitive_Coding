//?https://practice.geeksforgeeks.org/problems/steps-by-knight/0
#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n) {
    if(i >= 1 and i <= n and j >= 1 and j <= n)
        return true;
    return false;
}

int bfs(int i, int j, int x, int y, int n) {
    vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));

    queue<pair<int, pair<int, int>>> Q;
    Q.push({0,{i, j}});
    visited[i][j] = 1;

    int rows[] = {+2, +2, -2, -2, +1, +1, -1, -1};
    int cols[] = {+1, -1, +1, -1, +2, -2, +2, -2};

    while(!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        i = p.second.first;
        j = p.second.second;
        int dist = p.first;
        for(int k = 0; k < 8; k++) {
            int currRow = i + rows[k];
            int currCol = j + cols[k];

            if(currRow == x and currCol == y)
                return dist + 1;

            if(!isValid(currRow, currCol, n)) {
                continue;
            }
            if(visited[currRow][currCol] == 0) {
                Q.push({dist + 1, {currRow, currCol}});
                visited[currRow][currCol] = 1;
            }
        }
    }
    return 0;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2 and y1 == y2) {
            cout << 0 << endl;
            continue;
        }
        cout << bfs(x1, y1, x2, y2, n) << endl;
    }
}