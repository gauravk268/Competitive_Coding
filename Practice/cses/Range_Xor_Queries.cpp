#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
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

#define fr1(i,a,b) for(int i = (a); i <= (b); ++i)
#define fr(i,a) fr1(i,0,a)
#define rf1(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define rf(i,a) rf1(i,0,a)
#define trav(x,a) for (auto& x: a)

#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("test_input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

const int MX  = 2e6+5;
const int N   = 1e5+5;
const int MOD = 1e9+7;      // used in most problems
const ld  PI  = acos(-1);   // inverse cos of -1

ll seg[MX], a[MX];

void build(ll si, ll ss, ll se){
  if(ss==se){
    seg[si] = a[ss];
    return;
  }

  ll mid = ss + (se - ss) / 2;
  build(2 * si, ss, mid);
  build(2 * si + 1, mid + 1, se);

  seg[si] = seg[2 * si] ^ seg[2 * si + 1];
}

ll query(ll si, ll ss, ll se, ll qs, ll qe){
  if(qs>se || qe < ss){
    return 0;
  }

  if(ss>=qs && se<=qe){
    return seg[si];
  }

  ll mid = ss + (se - ss) / 2;
  ll l = query(2 * si, ss, mid, qs, qe);
  ll r = query(2 * si + 1, mid + 1, se, qs, qe);

  return l ^ r;
}

void solution(){
  ll n, q;
  cin >> n >> q;

  for (ll i = 1; i <= n; i++){
    cin >> a[i];
  }

  build(1, 1, n);

  ll a, b;
  while(q--){
    cin >> a >> b;
    cout << query(1, 1, n, a, b)<<endl;
  }

  return;
}

int main(){
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
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3

Output:
3
0
6
4

*/