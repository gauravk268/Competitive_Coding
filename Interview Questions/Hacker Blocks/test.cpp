#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN = 1e5 + 10;
vector<int> isprime;
vector<vector<int>> mat, ways;
int n, m;

void sieve() {
    isprime.assign(mxN, 1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i < mxN; i++) {
        if(isprime[i]) {
            for (int j = 2 * i; j < mxN; j+=i) {
                isprime[j] = 0;
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    ways.assign(n, vector<int>(m, 0));
    mat.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    sieve();
    ways[0][0] = 1;

    for (int j = 1; j < m; j++) {
        int a = mat[0][j];
        if(isprime[a]) {
            ways[0][j] = ways[0][j - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        int a = mat[i][0];
        if(isprime[a]) {
            ways[i][0] = ways[i - 1][0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int a = mat[i][j];
            if(!isprime[a]) {
                continue;
            }

            ways[i][j] = ways[i][j - 1] + ways[i - 1][j] + ways[i - 1][j - 1];
        }
    }

    vector<pair<int, int>> ans;
    ans.push_back({0, 0});

    int i = 0, j = 0;
    while(i < n && j < m) {
        
        if(i < n-1 && j < m-1 && ways[i+1][j+1] > 0) {
            ans.push_back({i + 1, j + 1});
            i += 1, j += 1;
        }
        else if(i < n-1 && ways[i+1][j] > 0) {
            ans.push_back({i + 1, j});
            i += 1;
        }
        else if (j < m-1 && ways[i][j+1] > 0) {
            ans.push_back({i, j + 1});
            j += 1;
        }
        else {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ways[i][j] << " ";
        }
        cout << endl;
    }

    cout << ways[n - 1][m - 1] << endl;
    if(ways[n-1][m-1] > 0) {
        for(auto p: ans) {
            cout << p.first+1 << " " << p.second+1 << endl;
        }
    }
}