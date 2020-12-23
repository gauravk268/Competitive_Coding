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
  ll x, y, n, k;   cin>>x>>y>>k>>n;

  if( (abs(x-y)%(2*k)) == 0)		cout<<"Yes\n";
	else	cout<<"No\n";
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
5
0 1 1 1
1 4 1 5
4 2 1 7
3 7 2 10
8 2 3 15
Example Output
No
No
Yes
Yes
Yes

*/