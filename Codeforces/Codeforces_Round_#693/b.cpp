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
  ll n;  cin>>n;
  ll ones=0, twos=0;

  while(n--){
    int temp;  cin>>temp;

    if(temp == 1)   ones++;
    else twos++;
  }
// 1 even >0   2 odd

  // if( (!(twos&1) && !(ones&1))  || (ones == 2*twos)){

  if( (!(twos&1) && !(ones&1))  || (!(ones&1) && ones>0 && (twos&1))){
    cout<<"YES\n";
  }
  else{
    cout<<"NO\n";
  }

  return;
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
5
2
1 1
2
1 2
4
1 2 1 2
3
2 2 2
3
2 1 2
outputCopy
YES
NO
YES
NO
NO

*/