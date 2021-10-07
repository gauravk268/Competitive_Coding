/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count=0;
    unordered_map<int,int> mp;
    int pathSum(TreeNode* root, int targetSum) {
        mp.clear();
        mp[0]=1;
        count=0;
        solve(root, targetSum, 0);
        return count;
    }
    
    void solve(TreeNode* root, int targetSum,int sum)
    {
        if(root==NULL)
            return;
        sum+=root->val;
        if(mp.find(sum-targetSum)!=mp.end())
            count+=mp[sum-targetSum];
        mp[sum]++;
        if(root->left)
            solve(root->left, targetSum, sum);
        if(root->right)
            solve(root->right, targetSum, sum);
        mp[sum]--;
    }
};