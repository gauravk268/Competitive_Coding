//?https://hack.codingblocks.com/app/contests/1783/1336/problem
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums) {
    int n = nums.size();
    if(n == 1)
        return nums[0];
    if(n == 2) {
        return max(nums[0], nums[1]);
    }

    int dp[n + 1];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[n - 1];
    
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int &num : nums) {
            cin >> num;
        }
        cout << solve(nums) << endl;

    }
}