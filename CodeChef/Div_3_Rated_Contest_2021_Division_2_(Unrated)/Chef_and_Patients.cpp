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

void solution(){
  int n;
  cin>>n;

  int temp, maxV=0;
  unordered_map<int, vi> q;
  for (int i = 0; i < n; i++){
    cin >> temp;
    q[temp].pb(i);

    maxV = max(maxV, temp);
  }

  int res[n];
  int k = 1;
  for(int i=maxV; i>=1; i--){
    for(auto e:q[i]){
      res[e] = k++;
    }
  }

  for (int i = 0; i < n; i++){
    cout << res[i] << " ";
  }
  cout << endl;
}

int main(){
  std::ios::sync_with_stdio(false);
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

4
5
2 3 5 3 4
3
2 2 2
6
2 10 3 3 2 10
4
8 9 8 9

5 3 1 4 2
1 2 3
5 1 3 4 6 2
3 1 4 2

*/