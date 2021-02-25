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

void fun(int a)
{
  if (a)
    cout << "YES";
  else
    cout << "NO";

  cout << endl;
}

void sol1()
{
  int n, m;
  cin >> n >> m;

  string s;
  unordered_map<int, int> col, row;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    for (int j = 0; j < m; j++)
    {
      if (s[j] == '1')
      {
        col[j]++;
        row[i]++;
      }
    }
  }

  int dx = 0, r = 0;
  for (int i = 0; i < n; i++)
  {
    if ((!r && row[i]) || (r && !row[i]))
    {
      dx++;
      r = row[i];
    }
    else
    {
      if (r != row[i])
      {
        fun(0);
        return;
      }
    }
  }

  int dy = 0, c = 0;
  for (int i = 0; i < m; i++)
  {
    if ((!c && col[i]) || (c && !col[i]))
    {
      dy++;
      c = col[i];
    }
    else
    {
      if (c != col[i])
      {
        fun(0);
        return;
      }
    }
  }

  if (dx > 2 || dy > 2)
  {
    fun(0);
  }
  else
  {
    fun(1);
  }
}

void solution()
{
  int n, m;
  cin >> n >> m;

  string s;
  char grid[n][m];
  int t=MOD, b=0, l=MOD, r=0;
  unordered_map<int, int> col, row;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    for (int j = 0; j < m; j++)
    {
      if (s[j] == '1')
      {
        col[j]++;
        row[i]++;

        t = min(t, i);
        b = max(b, i);
        l = min(l, j);
        r = max(r, j);
      }

      grid[i][j] = s[j];
    }
  }

  for (int i = t; i <= b; i++){
    for (int j = l; j <= r; j++){
      if(grid[i][j] == '0'){
        fun(0);
        return;
      }
    }
  }

  fun(1);
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // ONLINE_JUDGE;
  cin >> t;

  while (t--)
  {
    solution();
    // sol1();
  }

  showRunTime;
  return 0;
}

/*

Example Input
3
3 3
010
111
010
4 4
0000
0110
1110
1100
3 3
011
011
000

NO
NO
YES

*/