#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define dotl " "
#define MOD 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE                \
  freopen("input.txt", "r", stdin);

#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int static vis[1001][1001];
int static m, n;
char static a[1001][1001];

bool isvalid(int x, int y)
{
  if (x < 0 || x >= n || y < 0 || y >= m)
    return false;
  if (a[x][y] == '#')
    return false;
  return true;
}

void dfs(int a, int b)
{
  vis[a][b] = 1;
  for (int i = 0; i < 4; i++)
  {
    if (isvalid(a + dx[i], b + dy[i]))
    {
      dfs(a + dx[i], b + dy[i]);
    }
  }
  return;
}

void solution()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }
  int cc = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (vis[i][j] == 0)
      {
        cc++;
        dfs(i, j);
      }
    }
  }
  cout << cc;
  return;
}

int main()
{
  ONLINE_JUDGE;

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  //cin>>t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*
5 8
########
#..#...#
####.#.#
#..#...#
########
*/