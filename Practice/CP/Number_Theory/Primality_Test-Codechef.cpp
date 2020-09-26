#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x) 	 cout<<#x<<"="<<x<<endl

#define f  first
#define s  second
#define pb push_back
#define mp make_pair

// #define ENABLE_DEBUG


void solution()
{
	ll n;
	cin >> n;

	if(n==1 || n==0)
	{
		cout << "no" << endl;
		return;
	}

	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << "no" << endl;
			return;
		}
	}

	cout << "yes" << endl;
	return;
}

int main()
{
#ifdef ENABLE_DEBUG
	freopen("input.txt" , "r", stdin );
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;

	while (t--)
	{
		solution();
	}

	return 0;
}

/*
Input:
5
23
13
20
1000
99991

Output:
yes
yes
no
no
yes
*/