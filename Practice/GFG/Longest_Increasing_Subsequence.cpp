#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<ll> vll;

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define endl "\n"
#define trav(x, a) for (auto &x : a)
#define deb(x) cerr << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE                \
  freopen("input.txt", "r", stdin); \
  // freopen("output.txt", "w", stdout);

const int INF = 1e9 + 7;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7; // used in most problems

int fun(vi &val, int last, int i)
{
  if (i == 0)
  {
    if (val[i] < last)
      return 1;
    return 0;
  }

  if (val[i] < last)
  {
    return max(1 + fun(val, val[i], i - 1), fun(val, last, i - 1));
  }

  return fun(val, last, i - 1);
}

int funDP(vi &val, int n)
{
  int dp[n];

  dp[0] = 1;
  for (int i = 1; i < n; i++)
  {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
    {
      if (val[i] > val[j] && dp[i] < dp[j] + 1)
      {
        dp[i] = dp[j] + 1;
      }
    }
  }

  return *max_element(dp, dp + n);
}

void solution()
{
  int n;
  cin >> n;

  vi val(n);
  for (int i = 0; i < n; i++)
  {
    cin >> val[i];
  }

  // int count = 0;
  // for (int i = 0; i < n; i++)
  // {
  //   count = max(count, fun(val, 0, i));
  // }

  // cout << count << endl;

  cout << fun(val, INF, n - 1) << endl;
  cout << funDP(val, n) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  ONLINE_JUDGE;
  cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*

3
4
1 2 1 5
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
1
1

*/