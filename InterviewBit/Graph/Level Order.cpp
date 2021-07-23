/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> result;
    queue<TreeNode *> q;

    q.push(A);

    while(q.size()){
        int k=q.size();
        vector<int> tmp;
        while(k--){
            TreeNode *cur=q.front();
            tmp.push_back(cur->val);
            q.pop();

            if(cur->left)   q.push(cur->left);
            if(cur->right)  q.push(cur->right);
        }

        result.push_back(tmp);
    }

    return result;
}
