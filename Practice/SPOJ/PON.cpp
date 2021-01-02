#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define dotl " "
#define MOD 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fr(i,n)	  for(int i=0;i<n;i++)
#define fr1(i,n)	for(ll i=1;i<=n;i++)

ll mulMod(ll a, ll b, ll c){
  ll x=0, y=a%c;
  while(b>0){
    if(b%2 == 1){
      x = (x+y)%c;
    }

    y = (y*2LL)%c;
    b/=2;
  } 

  return x%c;
}

ll binPower(ll base, ll pow, ll mod){
  ll result = 1;

  while(pow){
    if(pow%2){
      result = mulMod(result, base, mod);
    }

    pow >>=1;
    base = mulMod(base, base, mod);
  }

  return result%mod;
}

bool isPrime(ll n, int iter=5){
  if(n<=4){
    return (n==2 || n==3);
  }

  for(int i=1; i<=iter; i++){
    ll a = 2 + rand()%(n-3);
    ll temp = binPower(a, n-1, n);

    if(temp != 1) return false;
  }

  return true;
}

void solution()
{
  ll n;  cin>>n;

  if(isPrime(n))
    cout<<"YES\n";
  else 
    cout<<"NO\n";
}

int main()
{
  // ONLINE_JUDGE;

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

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
2
3
4
5
6

Output:
YES
YES
NO
YES
NO

*/