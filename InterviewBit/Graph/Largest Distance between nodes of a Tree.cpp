int maxLen = 0;

int fun(vector<vector<int>> &tree, int node, int par)
{
  vector<int> k;

  for (auto &x : tree[node])
  {
    if (x != par)
    {
      k.push_back(fun(tree, x, node));
    }
  }

  sort(k.rbegin(), k.rend());

  if (k.size() == 1)
  {
    maxLen = max(maxLen, 1 + k[0]);
    return 1 + k[0];
  }
  else if (k.size() == 0)
  {
    maxLen = max(maxLen, 1);
    return 1;
  }

  maxLen = max(maxLen,1+k[0] + k[1]);
  return 1 + k[0];
}

int Solution::solve(vector<int> &A)
{
  int n = A.size();
  vector<vector<int>> tree(n, vector<int>());

  for (int i = 0; i < n; i++)
  {
    if (A[i] != -1)
    {
      tree[i].push_back(A[i]);
      tree[A[i]].push_back(i);
    }
  }

  maxLen=0;
  fun(tree, 0, -1);
  return maxLen - 1;
}
