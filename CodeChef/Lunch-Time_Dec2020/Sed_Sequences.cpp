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

void solution()
{
	int n, k;		cin>>n>>k;

	ll sum=0, res=0;
	for(int i=0; i<n; i++){
		cin>>res;
		sum+=res;
	}

	if(sum%k == 0)	cout<<0<<endl;
	else	cout<<1<<endl;
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

Example Input
3
3 2
1 1 1
3 3
1 1 1
5 5
1 2 3 4 5
Example Output
1
0
0

*/