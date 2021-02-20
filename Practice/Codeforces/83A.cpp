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

#define fr1(i,a,b) for(int i = (a); i <= (b); ++i)
#define fr(i,a) fr1(i,0,a)
#define rf1(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define rf(i,a) rf1(i,0,a)
#define trav(x,a) for (auto& x: a)

#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

const int MX  = 2e5+5;
const int N   = 1e5+5;
const int MOD = 1e9+7;      // used in most problems
const ld  PI  = acos(-1);   // inverse cos of -1

ll val[N];

ll fun(int n, int i){
  if(val[n]!=0){
    return val[n];
  }

  if(i<=1){
    return 0;
  }

  val[n] = (n - (i - 1)) + fun(n, i-1);
  return val[n];
}

void solution(){
  memset(val, 0, sizeof(val[0]) * N);

  int n;
  cin >> n;
  vll v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }

  ll res = 1, count=1, temp=v[0];
  for (int i = 1; i < n; i++){
    res++;
    if(v[i]==temp){
      count++;
    }
    else{
      res += fun(count, count);
      count = 1;
      temp = v[i];
    }
  }

  res += fun(count, count);

  cout << res << endl;
}

int main(){
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
4
2 1 1 4
5
-2 -2 -2 0 1

5
8

*/