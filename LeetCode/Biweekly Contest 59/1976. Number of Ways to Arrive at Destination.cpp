#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  typedef long long ll;
  int countPaths(int n, vector<vector<int>> &roads)
  {
    vector<pair<int, ll>> adj[n];
    for (auto x : roads)
    {
      adj[x[0]].push_back({x[1], ll(x[2])});
      adj[x[1]].push_back({x[0], ll(x[2])});
    }

    vector<ll> d(n, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, 0});
    d[0] = 0;

    vector<ll> count(n, 1);
    ll mod = 1e9 + 7;

    while (!pq.empty())
    {
      int node = pq.top().second;
      ll dis = pq.top().first;
      pq.pop();

      for (auto child : adj[node])
      {
        int childDis = child.first;
        ll childNode = child.second;

        if (childNode + dis < d[childDis])
        {
          pq.push({childNode + dis, childDis});
          d[childDis] = childNode + dis;
          count[childDis] = (count[node]) % mod;
        }
        else if (childNode + dis == d[childDis])
        {
          count[childDis] = (count[childDis] + count[node]) % mod;
        }
      }
    }

    return count[n - 1];
  }
};