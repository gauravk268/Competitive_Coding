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

int permutCoeff(int n, int k)
{
  if (k > n)
  {
    return 0;
  }

  if (k == 0)
  {
    return 1;
  }

  return permutCoeff(n - 1, k - 1) * k + permutCoeff(n - 1, k);
}

int permutCoeffNK(int n, int k)
{
  int res = 1;
  for (int i = 0; i < k; i++)
  {
    res *= (n - i);
  }

  return res;
}

void solution()
{
  int n = 10, k = 2;
  printf("Value of P(%d, %d) is %d \n", n, k, permutCoeff(n, k));
  printf("Value of P(%d, %d) is %d \n", n, k, permutCoeffNK(n, k));
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