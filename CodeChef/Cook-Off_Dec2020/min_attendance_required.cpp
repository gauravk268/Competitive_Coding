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
  int n;  cin>>n;
  string s;   cin>>s;

  int p=0;
  for(int i=0; i<n; i++){
    if(s[i]=='1') p++;
  }

  if((120-n+p) >= 90) cout<<"YES\n";
  else  cout<<"NO\n";
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

Sample Input:
3
50
00000000000000000000000000000000000000000000000000
50
01010101010101010101010101010101010101010101010101
2
01
Sample Output:
NO
YES
YES

*/