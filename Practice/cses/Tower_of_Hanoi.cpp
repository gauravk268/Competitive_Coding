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

vector<pair<int, int>> result;
void toi(int src, int dest, int help, int value)
{
  if (value == 1)
  {
    result.pb({src, dest});
    return;
  }

  toi(src, help, dest, value - 1);
  result.pb({src, dest});
  toi(help, dest, src, value - 1);
  return;
}

void solution()
{
  result.clear();
  int n;
  cin >> n;

  toi(1, 3, 2, n);
  cout << result.size() << endl;
  for (auto x : result)
  {
    cout << x.first << " " << x.second << endl;
  }
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

3
1 2
1 3
2 3

*/