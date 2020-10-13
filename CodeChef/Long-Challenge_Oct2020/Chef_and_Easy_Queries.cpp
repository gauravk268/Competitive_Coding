#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x) 	 cout<<#x<<"="<<x<<endl
#define showRunTime  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

#define f  first
#define s  second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

// #define ENABLE_DEBUG


void solution()
{
	ll n, k;	cin >> n >> k;

	vector<ll> values(n);
	for (int i = 0; i < n; i++)	cin >> values[i];

	if(values[0]<k)
	{
		cout<<1<<endl;
		return;
	}

	ll count = 0, remain = 0;
	for(int i=0; i<n; i++)
	{
		remain+=values[i];
		if(remain>=k)
			count++, remain-=k;
		else
		{
			cout<<i+1<<endl;
			return;
		}
	}

	if(remain >=k)	count+=(remain/k);
	cout << count+1 << endl;
}

int main()
{
#ifdef ENABLE_DEBUG
	freopen("stdin.txt", "r", stdin);
	freopen("stdout.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

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
Input
2
6 5
10 5 5 3 2 1
1 1
100

Output
6
101
*/