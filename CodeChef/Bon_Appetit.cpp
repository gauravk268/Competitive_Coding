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

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
  return a.s < b.s;
}

void solution()
{
  ll n, k;
  cin >> n >> k;

  map<ll, vector<pair<ll, ll>>> mp;
  while (n--)
  {
    ll a, b, c;
    cin >> a >> b >> c;

    mp[c].push_back({a, b});
  }

  ll result = 0;
  for (auto i = begin(mp); i != end(mp); i++)
  {
    sort(begin(mp[i->f]), end(mp[i->f]), cmp);
    ll tempRes = 1, endTime = mp[i->f][0].s;

    for (int j = 1; j < mp[i->f].size(); j++)
    {
      if (mp[i->f][j].f >= endTime)
      {
        tempRes++;
        endTime = mp[i->f][j].s;
      }
      else
      {
        endTime = min(endTime, mp[i->f][j].s);
      }
    }
    result += tempRes;
  }

  cout << result << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

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



*/