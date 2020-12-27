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
	int n;	cin>>n;
	string s, p;	cin>>s>>p;

	int sOnes=0, pOnes=0;
	for(int i=0; i<n; i++){
		if(s[i]=='1')		sOnes++;
		if(p[i]=='1')		pOnes++;

		if(pOnes > sOnes){
			cout<<"No"<<endl;
			return;
		}
	}

	if(sOnes == pOnes)		cout<<"Yes"<<endl;
	else 		cout<<"No"<<endl;	
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
2
00
00
3
101
010
4
0110
0011
Example Output
Yes
No
Yes

*/