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

vi A[MX];
int C[MX];

int dfs(int n)
{
  if(C[n]!=-1){
    return C[n];
  }

  if (A[n].size() == 0)
  {
    return C[n]=0;
  }

  int res = 0;
  for (auto c : A[n])
  {
    res += 1 + dfs(c);
  }

  return C[n]=res;
}

void solution()
{
  memset(C, -1, sizeof(C[0]) * MX);
  int n;
  cin >> n;

  for (int i = 2; i <= n; i++)
  {
    int temp;
    cin >> temp;
    A[temp].pb(i);
  }

  for (int i = 1; i <= n; i++)
  {
    if (i == 1)
    {
      cout << n - 1 << " ";
    }
    else
    {
      cout << dfs(i) << " ";
    }
  }

  cout << endl;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

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

Input:
5
1 1 2 3

Output:
4 1 1 0 0

*/