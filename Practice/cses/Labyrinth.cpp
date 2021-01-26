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
 
#define fr1(i,a,b) for(int i = (a); i < (b); ++i)
#define fr(i,a) fr1(i,0,a)
#define rf1(i,a,b) for(int i = (b)-1; i > (a); --i)
#define rf(i,a) rf1(i,0,a)
#define trav(x,a) for (auto& x: a)
 
#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
const int MX  = 2e5+5;
const int N   = 1e3+5;
const int MOD = 1e9+7;      // used in most problems
const ld  PI  = acos(-1);   // inverse cos of -1
 
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string stepDir = "URDL";
char grid[N][N];
pair<pi, char> par[N][N];
bool vis[N][N];
pi start, last;
 
bool isValid(int x, int y){
  if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || grid[x][y]=='#')
    return false;
  return true;
}
 
bool bfs(){
  queue<pi> q;
  q.push(start);
 
  while(!q.empty()){
    pi curr = q.front();
    q.pop();
    vis[curr.f][curr.s] = 1;
 
    fr(i, 4){
      pi nxt={curr.f+dx[i], curr.s+dy[i]};
 
      if(isValid(nxt.f, nxt.s)){
        vis[nxt.f][nxt.s] = 1;
        par[nxt.f][nxt.s] = {curr, stepDir[i]};
        if(nxt == last)
          return true;
        q.push(nxt);
      }
    }
  }
 
  return false;
}
 
void solution(){
  cin>> n >>m;
 
  fr(i, n)  fr(j, m){
    cin>>grid[i][j];
    if(grid[i][j]=='A')   start={i, j};
    if(grid[i][j]=='B')   last={i, j};
  }
 
  if(bfs()){
    
    string result="";
    pi nxt = last;
    while(nxt!=start){
      result += par[nxt.f][nxt.s].s;
      nxt = par[nxt.f][nxt.s].f;
    }
 
    reverse(all(result));
    cout<<"YES\n"<<result.length()<<endl<<result<<endl;
  }
  else{
    cout<<"NO\n";
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
5 8
########
#.A#...#
#.##.#B#
#......#
########
 
Output:
YES
9
LDDRRRRRU
 
*/