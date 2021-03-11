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
  string n;
  cin >> n;

  vi num(n.length());
  int count = 0;
  for (int i = 0; i < n.length(); i++)
  {
    num[i] = n[i] - '0';
    if ((num[i] & 1) == 0)
      count++;
  }

  if (count == 0)
  {
    cout << -1 << endl;
  }
  else
  {
    int ec = 0, oc = num.size() - 1;
    while (count--)
    {
      while ((num[ec] & 1) == 1)
      {
        ec++;
      }

      if (num[ec] < num[oc])
      {
        break;
      }
      else if (count)
      {
        ec++;
      }
    }

    swap(num[ec], num[oc]);
    for (auto x : num)
    {
      cout << x;
    }
    cout << endl;
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