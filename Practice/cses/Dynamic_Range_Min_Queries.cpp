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
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

const int MX  = 2e5+5;
const int N   = 1e6+5;
const int MOD = 1e9+7;      // used in most problems
const ld  PI  = acos(-1);   // inverse cos of -1

ll minSeg[N], ar[N];

void buildSeg(ll si, ll ss, ll se){
  if(ss == se){
    minSeg[si] = ar[ss];
    return;
  }

  ll mid = (ss + se)/2;
  buildSeg(2*si, ss, mid);
  buildSeg(2*si+1, mid+1, se);

  minSeg[si] = min( minSeg[2*si], minSeg[2*si+1] );
}

ll querySeg(ll si, ll ss, ll se, ll qs, ll qe){
  if(qs > se || qe < ss)  return MOD;
  if(ss >= qs && se <= qe)  return minSeg[si];

  ll mid = (ss + se)/2;
  ll l = querySeg(2*si, ss, mid, qs, qe);
  ll r = querySeg(2*si+1, mid+1, se, qs, qe);

  return min(l, r);
}

void updateSeg(ll si, ll ss, ll se, ll qi){
  if(ss == se){
    minSeg[si] = ar[ss];
    return;
  } 

  ll mid = (ss+se)/2;
  if(qi <= mid){
    updateSeg(2*si, ss, mid, qi);
  }
  else{
    updateSeg(2*si+1, mid+1, se, qi);
  }

  minSeg[si] = min( minSeg[2*si], minSeg[2*si+1]);
}

void solution(){
  ll n, m;  cin>>n>>m;
  for(int i=1; i<=n; i++)   cin>>ar[i];

  buildSeg(1, 1, n);
  ll a, b, c;
  while(m--){
    cin>>a>>b>>c;
    if(a==1){
      ar[b]=c;
      updateSeg(1, 1, n, b);
    }
    else{
      cout<<querySeg(1, 1, n, b, c)<<endl;
    }
  }

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
2 1 4
2 5 6
1 2 3
2 1 4

Output:
2
1
3

*/