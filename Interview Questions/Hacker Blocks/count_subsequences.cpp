//?https://hack.codingblocks.com/app/contests/1783/1101/problem
#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int solve(string s) {
    int n = s.length();
    int dp[n + 1];
    dp[0] = 1;

    map<char, int> mp;

    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * 2;
        dp[i] %= mod;

        if(mp.find(s[i - 1]) != mp.end()) {
            int j = mp[s[i - 1]];

            dp[i] = (dp[i] - dp[j - 1] + mod) % mod;
        }

        mp[s[i - 1]] = i;
    }
    return dp[n] % mod;

}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}