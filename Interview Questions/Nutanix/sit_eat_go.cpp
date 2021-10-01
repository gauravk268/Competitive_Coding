//?https://www.codechef.com/problems/FGFS
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<int, int> &a, pair<int, int> &b) {
  // if (a[1] == b[1]) {
  //   return a[0] < b[0];
  // }
  return a.second < b.second;
}

signed main() {
  // your code goes here
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    unordered_map<int, vector<pair<int, int>>> ump;
    for (int i = 0; i < n; i++) {
      int start, end, x;
      cin >> start >> end >> x;
      ump[x].push_back({start, end});
    }
    int cnt = 0;
    for (auto p : ump) {
      // cout << v[i].size();
      // vector<vector<int>> tmp = p.second;
      sort(p.second.begin(), p.second.end(), cmp);
      int start = p.second[0].first;
      int end = p.second[0].second;

      for (int j = 1; j < p.second.size(); j++) {
        if (end <= p.second[j].first) {
          cnt++;
          start = p.second[j].first;
          end = p.second[j].second;
        }
      }
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
