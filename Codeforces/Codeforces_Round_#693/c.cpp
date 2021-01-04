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

void solution()
{
  ll n;   cin>>n;

  vector<ll> value(n);
  ll maxValue=0, index=0;

  // unoredred_set<ll> u;

  for(int i=0; i<n; i++){
    cin>>value[i];

    if(maxValue < value[i]){
      maxValue = value[i];
      index = i;
    }
  } 

  // ll sum = accumulate(value.begin(), value.end(), 0);
  // if(sum == n){
  //   cout<<n<<endl;
  //   return;
  // }
  // else{ 
  //   if(sum-maxValue <=maxValue){
  //     cout<<maxValue<<endl;
  //     return;
  //   }
  // }

  // ll result=0, prev=0;
  // for(int i=0; i)

  vector<ll> temp(n);
  temp = value;

  ll step=0;
  fr(i, n){
    step = value[i];
    if(i+step < n){
      temp[i+step] = max(temp[i+step], temp[i]+value[i+step]);
    }
  }

  sort(temp.begin(), temp.end(), greater<ll>());
  cout<<temp[0]<<endl;
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

inputCopy
4
5
7 3 1 2 3
3
2 1 4
6
2 1000 2 3 995 1
5
1 1 1 1 1
outputCopy
7
6
1000
5

*/  