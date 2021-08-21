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

void solution()
{
  int n;
  cin >> n;

  vector<int> value(n);
  for (int i = 0; i < n; i++)
  {
    cin >> value[i];
  }

  if (n <= 3)
  {
    cout << *max_element(value.begin(), value.end()) << endl;
    return;
  }

  int dp[n];
  dp[0] = value[0];
  dp[1] = max(value[1], value[1] + dp[0]);
  dp[2] = max(value[2] + value[1], value[2] + dp[0]);

  // cout << dp[0] << " " << dp[1] << " " << dp[2] << endl;
  for (int i = 3; i < n; i++)
  {
    dp[i] = max(dp[i - 2] + value[i], max(dp[i - 1], value[i] + value[i - 1] + dp[i - 3]));
  }

  cout << dp[n - 1] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // ONLINE_JUDGE;
  // cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*

2
5 
10 3 5 7 3 
8
3 2 3 2 3 5 1 3

23
17

*/