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

void solution()
{
  int n;
  cin >> n;

  vll value(n);
  trav(x, value) cin >> x;
  sort(all(value));

  ll a, b, c;
  a = value[0];
  b = value[1];
  c = value[n - 1];

  int diffA = abs(b - a), diffC = abs(c - a), lastDiff = diffA + diffC;
  for (int i = 1; i < n - 1; i++)
  {
    diffA = abs(value[i] - a);
    diffC = abs(value[i] - c);

    if (lastDiff < diffA + diffC)
    {
      b = value[i];
      lastDiff = diffA + diffC;
    }
  }

  cout << abs(a - b) + abs(b - c) + abs(a - c) << endl;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // ONLINE_JUDGE;
  cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*

3
3
2 7 5
3
3 3 3
5
2 2 2 2 5

10
0
6

*/