#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[200005][3];

int solve(vector<int> &c,int i, int k, int x) {
    int n = c.size();
    if(i == 0) {
        return c[i] + solve(c, i + 1, k, x);
    }
    if(i == n - 1) {
        return c[i] + solve(c, i + 1, k, x);
    }
    if(i > n - 1) {
        return 0;
    }
    if(dp[i][k] != -1) {
        return dp[i][k];
    }
    int ans = LONG_MAX;
    if(k == 0) {
        int op1 = c[i] + solve(c, i + 1, 3, x);
        ans = min(ans, op1);
    } else {
        int op1 = c[i] + solve(c, i + 1, k, x);
        int op2 = x + solve(c, i + 1, k - 1, x);
        ans = min(ans, op1);
        ans = min(ans, op2);
    }
    return dp[i][k] = ans;
}


signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> shops(n);

    for(int i = 0; i < n; i++) {
        cin >> shops[i];
    }

}