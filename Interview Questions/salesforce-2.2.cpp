#include<bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    int candy[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> candy[i][j];
        }
    }

    int dp[n][n];
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = candy[i][j];
        }
    }
    // We are trying to calculate that how many maximum candies can we get from each row
    // which is denoted by the last element in the dp array
    for(int i = 0; i < n; i++) {
        int mx = dp[i][0];

        for(int j = 2; j < n; j++) {
            dp[i][j] = max(mx + candy[i][j], dp[i][j - 1]);
            mx = max(mx, dp[i][j - 1]);
        }
    }
    // We we choose any candies from a row than we can't take candies from just above and below row
    // so we are taking alternatively and checking which is maximum

    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2) {
            ans1 += dp[i][n - 1];
        } else {
            ans2 += dp[i][n -1];
        }
    }
    cout << max(ans1, ans2) << endl;
}