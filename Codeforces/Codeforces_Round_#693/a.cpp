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
  ll w, h, n;   cin>>w>>h>>n;

  if((w&1) && (h&1)){
    
    if(n==1 || n==0)  cout<<"YES\n";
    else cout<<"NO\n";  

    return;
  }

  ll area = w*h;
  ll parts=1;

  while(!(area&1)){
    parts = parts*2;
    area = area >> 1;
  }

  if(parts >= n)   cout<<"YES\n";
  else cout<<"NO\n";
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
2 2 3
3 3 2
5 10 2
11 13 1
1 4 4
outputCopy
YES
NO
YES
YES
YES

*/