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

void solution()
{
  int n, m;
  cin >> n >> m;

  map<string, string> mp1, mp2;
  for (int i = 0; i < m; i++)
  {
    string a, b;
    cin >> a >> b;

    mp1[a] = b;
  }

  vector<string> lec(n);
  string result = "";
  for (int i = 0; i < n; i++)
  {
    string a;
    cin >> a;

    a.length() <= mp1[a].length() ? result += a : result += mp1[a];
    if (i != n - 1)
    {
      result += " ";
    }
  }

  cout << result << endl;
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



*/