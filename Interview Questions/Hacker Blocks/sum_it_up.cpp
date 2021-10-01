//?https://hack.codingblocks.com/app/contests/1783/621/problem
#include<bits/stdc++.h>
using namespace std;
set<vector<int>> ans;

void solve(vector<int> &nums, int i, int sum, int targetSum, vector<int> curr) {
    int n = nums.size();
    if(i > n or sum  > targetSum) {
        return;
    }
    if(sum == targetSum) {
        sort(curr.begin(), curr.end());
        ans.insert(curr);   
    }
    if(i == n)
        return;
        
    curr.push_back(nums[i]);
    solve(nums, i + 1, sum + nums[i], targetSum, curr);
    curr.pop_back();
    solve(nums, i + 1, sum, targetSum, curr);

    vector<int> curr2;
    curr2.push_back(nums[i]);
    solve(nums, i + 1, nums[i], targetSum, curr2);
}

signed main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int &num : nums)
        cin >> num;
    int targetSum;
    cin >> targetSum;
    vector<int> curr;
    ans.clear();
    solve(nums, 0, 0, targetSum, curr);
    for(auto v : ans) {
        for(auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

}