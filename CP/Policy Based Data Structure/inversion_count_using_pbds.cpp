#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

/*
    !NOTE : This PBDS works on 
            1. Leetcode
            2. Hackerrank
            3. Codeforces
            4. Codechef
*/

signed main() {

    PBDS St;

    // Distinct Case
    int n;
    cin >> n; // 7
    vector<int> nums(n); // 1 5 2 3 6 4 10

    for(auto &num : nums)
        cin >> num;

    int inversionCnt = 0;

    for(int i = 0; i < n; i++) {
        inversionCnt += (St.size() - St.order_of_key(nums[i]));
        St.insert(nums[i]);
    }

    cout << inversionCnt << endl;
     
}