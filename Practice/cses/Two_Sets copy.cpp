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
  ll n;
  cin >> n;

  ll total = (n * (n + 1)) / 2;
  if (total & 1){
    cout << "NO" << endl;
    return;
  }

  vi v1, v2;
  total /= 2;
  while(n){
    if(total - n >=0){
      v1.pb(n);
      total -= n;
    }
    else{
      v2.pb(n);
    }

    n--;
  }

  cout << "YES" << endl;
  cout << v1.size() << endl;
  for(auto x: v1){
    cout << x << " ";
  }

  cout << endl << v2.size() << endl;
  for(auto x: v2){
    cout << x << " ";
  }
  cout << endl;
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