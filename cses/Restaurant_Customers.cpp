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
  int n;
  cin >> n;

  vector<pi> val;
  int a, b;
  for (int i = 0; i < n; i++){
    cin >> a >> b;
    val.pb({a, 1});
    val.pb({b, -1});
  }

  sort(all(val));

  int sum = 0, finalSum = 0;
  for(auto x:val){
    sum += x.s;
    finalSum = max(finalSum, sum);
  }

  cout << finalSum << endl;
  return;
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



*/