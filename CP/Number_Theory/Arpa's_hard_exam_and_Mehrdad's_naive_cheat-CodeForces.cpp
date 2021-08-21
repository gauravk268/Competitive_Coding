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
#define mp make_pair

// #define ENABLE_DEBUG


void solution()
{
	int n, c = 8, res = 1;
	cin >> n;

	while (n)
	{
		if (n % 2)
		{
			res = (res * c) % 10;
			n--;
		}
		else
		{
			c = (c * c) % 10;
			n /= 2;
		}
	}

	cout << res % 10 << endl;
}

int main()
{
#ifdef ENABLE_DEBUG
	freopen("stdin.txt", "r", stdin);
	freopen("stdout.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin>>t;

	while (t--)
	{
		solution();
	}

	showRunTime;
	return 0;
}

/*
inputCopy
1
outputCopy
8

inputCopy
2
outputCopy
4

8 4 6 6 6
*/