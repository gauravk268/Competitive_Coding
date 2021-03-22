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
  freopen("outputP.txt", "w", stdout);

const int INF = 1e9 + 7;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7; // used in most problems

void solution1()
{
  int n, a, b;
  cin >> n >> a >> b;

  long long steps[n + 1] = {0};

  for (int i = 0; i <= n; i++)
  {
    if (i >= a && i <= b)
    {
      steps[i]++;
    }
    for (int j = a; j <= b && i - j > 0; j++)
    {
      steps[i] += steps[i - j];
      steps[i] = steps[i] % MOD;
    }
  }

  cout << steps[n] << endl;
  showRunTime;
}

void solution()
{
  int n, a, b;
  cin >> n >> a >> b;

  long long steps[n + 1] = {0};

  for (int i = a; i <= min(b, 2 * a) && i <= n; i++)
  {
    steps[i] = 1;
  }

  for (int i = min(b, 2 * a); i <= b; i++)
  {
    for (int j = a; j < b; j++)
    {
      if (i - j > 0)
        steps[i] += steps[i - j];
      steps[i] = steps[i] % MOD;
    }
  }

  for (int i = b + 1; i <= n; i++)
  {
    for (int j = a; j <= b; j++)
    {
      if (i - j > 0 && steps[i - j] > 0)
        steps[i] += steps[i - j];
      else
        break;
      steps[i] = steps[i] % MOD;
    }
  }

  // if (n == 1785)
  // {
  //   cout << endl;
  //   for (int i = 0; i <= n; i++)
  //   {
  //     cout << i << " " << steps[i] << endl;
  //   }
  //   cout << endl;
  // }

  cout << steps[n] << endl;
  showRunTime;
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
    // solution();
    solution1();
  }

  // showRunTime;
  return 0;
}

/*



*/