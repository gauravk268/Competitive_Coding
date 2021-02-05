#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define dotl " "
#define MOD 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define fr1(i, n) for (ll i = 1; i <= n; i++)

int countSubsetSum(vector<int> &value, int sum)
{
  int n = value.size();
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

  for (int i = 0; i <= n; i++)
    dp[i][0] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= sum; j++)
    {
      // if (value[i - 1] <= j)
      if (dp[i-1][j-1] >= sum)
        dp[i][j] = dp[i - 1][j - value[i - 1]] + dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  return dp[n][sum];
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> value(n);
  fr(i, n) cin >> value[i];

  if (accumulate(value.begin(), value.end(), 0) < 2 * k)
  {
    cout << "-1" << endl;
    return;
  }

  if (countSubsetSum(value, k) >= 2)
  {
    cout << "yes\n";
  }
  else
  {
    cout << "No\n";
  }
}

int main()
{
  ONLINE_JUDGE;

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*

Example Input
2
8 38
7 8 19 7 8 7 10 20
4 5
2 10 4 9
Example Output
7
2

*/