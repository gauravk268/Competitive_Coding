class Solution
{
public:
  bool vis[100005];
  void dfs(vector<vector<int>> &adj, int k, vector<set<int>> &values)
  {
    if (adj[k].size() == 0)
      return;

    if (!vis[k])
    {
      for (auto x : adj[k])
      {
        dfs(adj, x, values);
        for (auto y : values[x])
        {
          values[k].insert(x);
        }
      }
    }

    vis[k] = true;
  }

  vector<int> maxGeneticDifference(vector<int> &p, vector<vector<int>> &q)
  {
    int n = p.size();
    vector<vector<int>> adj(n);
    vector<set<int>> values(n);

    memset(vis, 0, sizeof(vis));
    int root;
    for (int i = 0; i < n; i++)
    {
      if (p[i] == -1)
        root = i;
      else
        adj[i].push_back(p[i]);
    }

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      dfs(adj, i, values);
      values[i].insert(i);
    }

    for (auto &x : q)
    {
      int node = x[0];
      int value = x[1];
      int res = value;

      for (auto y : x)
      {
        if (value ^ y > res)
          res = y;
      }

      result.push_back(res);
    }

    return result;
  }
};