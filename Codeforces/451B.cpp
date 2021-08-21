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
  int n;
  cin >> n;

  vi a(n), b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(all(b));

  map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    mp[b[i]] = i;
  }

  for (int i = 0; i < n; i++)
  {
    a[i] = mp[a[i]];
  }

  int L = -1, R = -1;
  for (int i = 0; i < n; i++)
  {
    if (a[i] != i)
    {
      L = i;
      break;
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i] != i)
    {
      R = i;
      break;
    }
  }

  if (L == -1 || R == -1)
  {
    cout << "yes" << endl;
    cout << 1 << " " << 1 << endl;
  }
  else
  {
    reverse(a.begin() + L, a.begin() + R + 1);
    for (int i = 0; i < n; i++)
    {
      if (a[i] != i)
      {
        cout << "no" << endl;
        return;
      }
    }

    cout << "yes" << endl;
    cout << L + 1 << " " << R + 1 << endl;
  }
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