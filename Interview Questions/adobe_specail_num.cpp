#include<bits/stdc++.h>
using namespace std;

signed main() {
    int a, b;
    cin >> a >> b;

    vector<int> nums(b - a + 1, 0);

    int i = floor(sqrt(a));
    cout << i << endl;
    if(i == 1) {
        i++;
    }
    while(i * i <= b) {
        int x = i * i;
        // cout << x << endl;
        for(int j = x; j <= b; j += x) {
            // cout << j << endl;
            if(j - a >= 0) {
                nums[j - a] = 1;
            }
        }
        i++;
    }
    // for(int j = 0; j < nums.size(); j++) {
    //     cout << nums[j] << " ";
    // }
    // cout << endl;
    int cnt = 0;
    for(int j = 0; j < nums.size(); j++) {
        if(nums[j] == 0)
            cnt++;
    }
    cout << cnt << endl;
}