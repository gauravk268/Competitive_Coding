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
  int n, k;
  cin >> n >> k;

  vi v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }

  deque<int> res;
  int mid = (k + 1) / 2;
  mid--;
  int r = 0;
  for (int i = 0; i < n; i++){
    if(res.size() < k-1){
      res.pb(v[i]);
    }
    else{
      res.pb(v[i]);

      vi h;
      for(auto d:res){
        h.pb(d);
      }
      sort(all(h));

      for (auto d: h){
        cout << d << " ";
      }
      cout << endl;

      r = max(h[mid], r);
      res.pop_front();
    }
  }

  cout << r << endl;
}

int main()
{
  std::ios::sync_with_stdio(false);
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

2
5 3
1 2 3 2 1
4 2
1 2 3 4

2
3

*/