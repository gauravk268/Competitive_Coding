#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ull unsigned long long
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

#define fr1(i, a, b) for (int i = (a); i < (b); ++i)
#define fr(i, a) fr1(i, 0, a)
#define rf1(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define rf(i, a) rf1(i, 0, a)
#define trav(x, a) for (auto &x : a)

#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

const int MX = 2e5 + 5;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7; // used in most problems
const ld PI = acos(-1);  // inverse cos of -1

int vis[N][N] = {0};
char rooms[N][N];
int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void dfs(int x, int y)
{
  vis[x][y] = 1;

  int newX, newY;
  fr(i, 4)
  {
    newX = x + dx[i];
    newY = y + dy[i];

    if ((newX >= 0) && (newX < n) && (newY >= 0) && (newY < m) && (!vis[newX][newY]) && rooms[newX][newY] == '.')
      dfs(newX, newY);
  }
}

void solution()
{
  cin >> n >> m;

  fr(i, n) fr(j, m) cin >> rooms[i][j];

  int count = 0;
  fr(i, n) fr(j, m)
    if (rooms[i][j] == '.' && !vis[i][j])
      dfs(i, j), count++;

  cout << count << endl;
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
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3

*/