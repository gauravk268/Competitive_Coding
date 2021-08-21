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
class Solution
{
public:
  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode *, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while (q.size())
    {
      pair<TreeNode *, pair<int, int>> cur = q.front();
      q.pop();

      mp[cur.second.first][cur.second.second].insert(cur.first->val);

      if (cur.first->left)
      {
        q.push({cur.first->left, {cur.second.first - 1, cur.second.second + 1}});
      }

      if (cur.first->right)
      {
        q.push({cur.first->right, {cur.second.first + 1, cur.second.second + 1}});
      }
    }

    vector<vector<int>> result;
    for (auto &x : mp)
    {
        vector<int> tmp;
      for (auto &y : x.second)
      {
        
        for (auto &z : y.second)
        {
          tmp.push_back(z);
        }
          
      }
        result.push_back(tmp);
    }

    return result;
  }
};