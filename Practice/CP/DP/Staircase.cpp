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
  int n, l;
  cin >> n >> l;

  if (l == 1)
  {
    cout << n << endl;
    return;
  }

  ll dp[n + 1], sum = 0;
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= l; i++)
  {
    if (i <= 2)
    {
      dp[i] = i;
    }
    else
    {
      dp[i] = sum + 1;
    }

    sum += dp[i];
  }

  for (int i = l + 1; i <= n; i++)
  {
    for (int j = 1; j <= l; j++)
    {
      dp[i] += dp[i - j];
    }
  }

  cout << dp[n] << endl;
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

2
5 3
3 2

*/