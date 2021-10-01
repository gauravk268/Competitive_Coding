#include<bits/stdc++.h>
using namespace std;



struct TreeNode {
   int data;
   TreeNode* leftChild;
   TreeNode* rightChild;
};

int solve(TreeNode* root) {
   if(root == NULL)
      return 0;
   int val = root->data;
   int leftChildSum = solve(root->left);
   int rightChildSum = solve(root->right);

   root->data = leftChildSum + rightChildSum;

   return val + root->data;
}

void solve(TreeNode* root) {
   queue<pair<TreeNode*, int>> Q;
   Q.push({root, 0});

   map<int, vector<int>> mp; // Storing each level

   while(!Q.empty()) {
      pair<TreeNode*, int> p = Q.front();
      Q.pop();

      int data = p.first->data;
      int d = p.second;
      mp[d].push_back(data);

      if(p.first->leftChild) {
         Q.push({p.first->leftChild, d + 1});
      }
      if(p.first->rightChild) {
         Q.push({p.first->rightChild, d + 1});
      }
   }
   // First node of the each level
   for(auto p : mp) {
      vector<int> v = p.second;

      cout << v[0] << endl;
   }
}

signed main() {
   int n;
   cin >> n;
   vector<vector<int>> mat(n, vector<int>(n));

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cin >> mat[i][j];
      }
   }

   solve(mat);

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cout << mat[i][j] << " ";
      }
      cout << endl;
   }


}