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
const int N   = 1e5+5;
const int MOD = 1e9+7;      // used in most problems
const ld  PI  = acos(-1);   // inverse cos of -1

void solution(){
  int n;
  cin >> n;

  vi weight(n), jump(n);
  trav(x, weight) cin >> x;
  trav(x, jump) cin >> x;

  priority_queue<pi, vpi, greater<pi>> minH;
  unordered_map<int, int> m;
  for (int i = 0; i < n; i++){
    minH.push({weight[i], jump[i]});
    m[weight[i]] = i+1;
  }

  pi c = minH.top();
  minH.pop();
  int result = 0, lastLoc=m[c.f];

  while(!minH.empty()){
    c = minH.top();
    minH.pop();

    if(m[c.f] <= lastLoc){
      int step = ((lastLoc - m[c.f])/c.s)+1;
      result += step;
      lastLoc = m[c.f] + step * c.s;
      m[c.f] = lastLoc;
    }
    else{
      lastLoc = m[c.f];
    }
  }

  cout << result << endl;
}

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

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

3
3
3 1 2
1 4 5
3
3 2 1
1 1 1
4
2 1 4 3
4 1 2 4

3
6
5

*/