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
	string s;		cin>>s;

	unordered_map<char, int> value;
	int n=s.length();

	if(n<3){
		cout<<0<<endl;
		return;
	}

	int freq[26]={0};
	for(int i=0; i<n; i++){
		freq[ abs('a'-s[i]) ]++;
	}

	int pairs=0, singles=0, res=0; 
	for(int i=0; i<26; i++){
		// pairs+=freq[i]/2;
		// singles += freq[i]%2;

		res += freq[i]/2;
	}

	cout<<min(res, n/3)<<endl;

	// int result=0;
	// if(singles >= pairs){
	// 	result += pairs;
	// }
	// else{
	// 	result += singles;
	// 	pairs -= singles;

	// 	result += (pairs*2)/3;
	// }
	// cout<<result<<endl;
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
2
abcd
codechef
Example Output
0
2


*/