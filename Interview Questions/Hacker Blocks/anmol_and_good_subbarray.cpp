//?https://hack.codingblocks.com/app/contests/1783/1739/problem
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    map<int, int> mp;
    int start = 0, sum = 0, ans = 0;
    mp[0] = 1; // when prefix is zero it means that from the 0th index the subarray have sum zero till now
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];

        start = max(start, mp[sum]);
        ans += (i - start + 1); 
        mp[sum] = i + 2; // storing the index which can become next potential start point
    }
    cout << ans << endl;
}