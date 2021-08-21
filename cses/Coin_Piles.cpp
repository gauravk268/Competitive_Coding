#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define endl "\n"
#define trav(x,a) for (auto& x: a)
#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

const int INF = 1e9+7;
const int N   = 1e5+5;
const int MOD = 1e9+7;      // used in most problems

void solution(){
  ll a, b;
  cin >> a >> b;

  if(2*a==b || 2*b==a){
    cout << "YES\n";
    return;
  }

  if((a+b)%3!=0 || a>2*b || b>2*a){
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  return;
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



*/