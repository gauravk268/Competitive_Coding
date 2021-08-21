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
int n;
int vis[N], team[N];

bool biPartDFS(int n, int t)
{
  vis[n] = 1;
  team[n] = t;

  for (auto i : adj[n])
  {
    if (!vis[i])
    {
      if (biPartDFS(i, t ^ 1) == false)
        return false;
    }
    else
    {
      if (team[i] == team[n])
        return false;
    }
  }

  return true;
}

void solution()
{
  int m;
  cin >> n >> m;

  int a, b;
  while (m--)
  {
    cin >> a >> b;

    adj[a].pb(b);
    adj[b].pb(a);
  }

  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      if (biPartDFS(i, 0) == false)
      {
        cout << "IMPOSSIBLE\n";
        return;
      }
    }
  }

  int t = team[1];
  for (int i = 1; i <= n; i++)
  {
    if (team[i] == t)
    {
      cout << "1 ";
    }
    else
    {
      cout << "2 ";
    }
  }

  cout << endl;
}

int main()
{
  // ONLINE_JUDGE;

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*

Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2

*/