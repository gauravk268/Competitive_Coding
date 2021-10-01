//?https://hack.codingblocks.com/app/contests/1783/1263/problem
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m, c;
    cin >> n >> m >> c;

    map<int, int> mp;
    vector<int> nums(n);

    for(int &num : nums) {
        cin >> num;
        mp[num]++;
    }
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        int x = nums[i];
        int y = m * x + c;

        cnt += mp[y];
        if(x == y)
            cnt--;
    }
    cout << cnt << endl;
}