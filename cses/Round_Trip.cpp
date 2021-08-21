#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define bk back()
#define pb push_back
#define endl "\n"
#define dotl " "

#define fr1(i, a, b) for (int i = (a); i <= (b); ++i)
#define fr(i, a) fr1(i, 0, a)
#define rf1(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define rf(i, a) rf1(i, 0, a)
#define trav(x, a) for (auto &x : a)

#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

const int MX = 2e5 + 5;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7; // used in most problems
const ld PI = acos(-1);  // inverse cos of -1

vi adj[N];
int par[N], vis[N] = {0};
bool flag;
int c = 0;

void dfs(int n, int p)
{
  vis[n] = 1;
  par[n] = p;

  for (auto i : adj[n])
  {
    if (!vis[i])
    {
      dfs(i, n);
    }
    else
    {
      if (i != p)
      {
        vi result;
        int curr = n;
        result.pb(curr);
        while (par[curr] != i)
        {
          if (flag)
            return;

          curr = par[curr];
          result.pb(curr);
        }

        result.pb(i);
        result.pb(n);

        cout << result.size() << endl;
        trav(i, result)
        {
          cout << i << " ";
        }

        flag = true;
        return;
      }
    }
  }
}

void solution()
{
  flag = false;
  int n, m;
  cin >> n >> m;

  int a, b;
  while (m--)
  {
    cin >> a >> b;

    adj[a].pb(b);
    adj[b].pb(a);
  }

  for (int i = 1; i <= n && !flag; i++)
  {
    if (!vis[i])
    {
      dfs(i, -1);
    }

    if (flag)
      return;
  }

  cout << "IMPOSSIBLE\n";
  return;
}

int main()
{
  // ONLINE_JUDGE;

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*

Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3

*/