#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
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

  vector<string> val(n);
  vector<bitset<5>> count(n, 0);
  for (int i = 0; i < n; i++){
    cin >> val[i];

    for (auto j:val[i]){
      if(j=='a')
        count[i][0] = 1;

      if(j=='e')
        count[i][1] = 1;

      if(j=='i')
        count[i][2] = 1;

      if(j=='o')
        count[i][3] = 1;

      if(j=='u')
        count[i][4] = 1;
    }
  }

  int result = 0;
  for (int i = 1; i < pow(2, n); i++){
    bitset<5> temp=0;

    for (int j = 1; j < n; j++){
      if(i & (1<<j)){
        temp = temp | count[j];
      }
    }

    if(temp == 31){
      result++;
    }
  }

  cout << result << endl;
}

void fun(){
  int n;
  cin >> n;

  string st;
  ll F[32];
  for (int i = 0; i < 32; i++)
    F[i] = 0;

  for (int i = 1; i <= n; i++){
    cin >> st;

    int mask=0;
    for(char ch:st){
      if(ch=='a')
        mask = mask | (1<<0);

      if(ch=='e')
        mask = mask | (1<<1);

      if(ch=='i')
        mask = mask | (1<<2);

      if(ch=='o')
        mask = mask | (1<<3);

      if(ch=='u')
        mask = mask | (1<<4);
    }

    F[mask]++;
  }

  ll res = 0;
  for (int i = 1; i < 32; i++){
    for (int j = i + 1; j < 32; j++){
      if((i|j) == 31){
        res = res + F[i] * F[j];
      }
    }
  }

  res = res + ((F[31] * (F[31] - 1)) / 2);
  cout << res << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // ONLINE_JUDGE;
  cin >> t;

  while (t--)
  {
    // solution();
    fun();
  }

  showRunTime;
  return 0;
}

/*

1
3
aaooaoaooa
uiieieiieieuuu
aeioooeeiiaiei

2

*/