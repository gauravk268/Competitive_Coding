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

int binomialCoeff(int n, int k)
{
  if (n == k || k == 0)
  {
    return 1;
  }

  return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

int binomialCoeffDP(int n, int k)
{
  int dp[n + 1][k + 1];

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= min(i, k); j++)
    {
      if (i == j || j == 0)
      {
        dp[i][j] = 1;
      }
      else
      {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
    }
  }

  return dp[n][k];
}

void solution()
{
  int n = 5, k = 2;
  cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeff(n, k) << endl;
  cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeffDP(n, k) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  ONLINE_JUDGE;
  // cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*



*/