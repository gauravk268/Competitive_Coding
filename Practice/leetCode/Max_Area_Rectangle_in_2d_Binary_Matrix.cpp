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

int maxHist(int *hist, int n)
{
  stack<int> s;

  int max_area = 0, tp, area_with_top, i = 0;
  while (i < n)
  {
    if (s.empty() || hist[s.top()] <= hist[i])
      s.push(i++);
    else
    {
      tp = s.top();
      s.pop();

      area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
      max_area = max(max_area, area_with_top);
    }
  }

  while (s.empty() == false)
  {
    tp = s.top();
    s.pop();

    area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
    max_area = max(max_area, area_with_top);
  }

  return max_area;
}

void solution()
{
  int n, m;
  cin >> n >> m;

  int mat[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
    }
  }

  vector<vector<int>> k(n, vector<int>(m));

  int dp[n][m];
  for (int j = 0; j < m; j++)
  {
    dp[0][j] = mat[0][j];
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      dp[i][j] = mat[i][j];

      if (mat[i][j] == 1)
      {
        if (dp[i - 1][j])
        {
          dp[i][j] += dp[i - 1][j];
        }
      }
    }
  }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     cerr << dp[i][j] << " ";
  //   }
  //   cerr << endl;
  // }

  int res = 0;
  for (int i = 0; i < n; i++)
  {
    int temp;
    temp = maxHist(dp[i], m);
    res = max(res, temp);
  }

  cout << res << endl;
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

4
3 3
1 1 1
0 1 1
1 0 0
2 2
0 1
1 0
8 9
0 0 1 0 0 0 1 0 1
0 1 1 0 0 0 0 0 0
0 0 1 0 1 0 1 0 1
0 1 0 0 0 1 1 0 1
0 1 0 0 0 0 1 1 1
1 0 1 1 1 0 1 1 1
1 1 1 1 0 1 1 1 1
1 1 1 0 1 0 1 0 1
15 15
1 1 1 1 1 1 0 1 1 1 1 1 1 1 1
1 0 1 1 0 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 1 1 1 1 1 1 0 1 1 1 0 1 1 1
1 0 0 1 1 1 1 1 1 1 1 0 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1 1 0 1 1 1
1 1 1 1 0 0 0 1 1 1 1 1 0 1 0
1 0 1 1 0 0 0 1 1 1 1 0 1 0 1
1 0 1 1 1 1 1 1 0 1 1 1 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 0 1 0 1 1 1 1 1 1 1
1 1 1 1 1 1 0 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0 1 1 1 1 1 0 1

*/