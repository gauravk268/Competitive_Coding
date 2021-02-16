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

vi adj[MX];
int maxNode, maxDis, dis[MX], vis[MX];

void dfs(int n, int d){
  vis[n] = 1;
  dis[n] = d;

  if(d > maxDis){
    maxDis = d;
    maxNode = n;
  }

  for(auto c:adj[n]){
    if(!vis[c])
      dfs(c, d + 1);
  }
}

void solution(){
  maxNode = 0;
  maxDis = 0;
  memset(dis, 0, sizeof(dis[0]) * MX);
  memset(vis, 0, sizeof(vis[0]) * MX);
  int n;
  cin >> n;

  int m = n - 1;
  int a, b;
  while(m--){
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  for (int i = 1; i <= n; i++){
    if(!vis[i])
      dfs(i, 0);
  }

  memset(dis, 0, sizeof(dis[0]) * MX);
  memset(vis, 0, sizeof(vis[0]) * MX);
  vis[maxNode] = 1;
  dfs(maxNode, 0);

  cout << maxDis << endl;
}

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

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

Input:
5
1 2
1 3
3 4
3 5

Output:
3

*/