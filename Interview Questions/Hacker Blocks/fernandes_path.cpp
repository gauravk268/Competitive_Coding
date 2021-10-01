//?https://hack.codingblocks.com/app/contests/1783/1748/problem
#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100005
#define int long long
vector<bool> isPrime(MAX_SIZE, 1);
int dp[1001][1001];
int mod = 1e9 + 7;

void prime() {

    for(int p = 2; p * p < MAX_SIZE; p++) {
        if(isPrime[p] == true) {
            for(int i = p * p; i < MAX_SIZE; i += p) {
                isPrime[i] = false;
            }
        }
    }
    isPrime[0] = 0;
    isPrime[1] = 0;
    
}

bool check(int i, int j, int n, int m) {
    if(i >= 0 and i < n and j >= 0 and j < m)
        return true;
    return false;
}



int dfs(vector<vector<int>> &mat, int i, int j) {
    int n = mat.size();
    int m = mat[0].size();

    if(!check(i, j, n, m)) {
        return 0;
    }
    if(isPrime[mat[i][j]] == 0)
        return 0;

    if(i == n - 1 and j == m - 1)
        return 1;
    
    
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int path1 = dfs(mat, i + 1, j);
    path1 %= mod;
    int path2 = dfs(mat, i, j + 1);
    path2 %= mod;
    int path3 = dfs(mat, i + 1, j + 1);
    path3 %= mod;

    return dp[i][j] = (path1 + path2 + path3) % mod;
    
}

signed main() {
    int n, m;
    cin >> n >> m;
    prime();

    vector<vector<int>> mat(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    
    int ans =  dfs(mat, 0, 0);
    cout << ans << endl;
    dp[n - 1][m - 1] = 1;
    int i = 0, j = 0;
    while(i < n and j < m and ans != 0) {
        cout << i + 1 << " " << j + 1 << endl;
        if(check(i + 1, j + 1, n, m) and dp[i + 1][j + 1] != -1 and dp[i + 1][j + 1] != 0) {
            // cout << i + 2 << " " << j + 2 << endl;
            i++;
            j++;
        } else if(check(i + 1, j, n, m) and dp[i + 1][j] != -1 and dp[i + 1][j] != 0) {
            // cout << i + 2 << " " << j + 1 << endl;
            i++;
        } else if(check(i, j + 1, n, m) and dp[i][j + 1] != -1 and dp[i][j + 1] != 0){
            // cout << i + 1 << " " << j + 2 << endl;
            j++;
        } else {
            break;
        }
    }

}
