#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x) 	 cout<<#x<<"="<<x<<endl
#define range 900000001

// #define ENABLE_DEBUG

bool ar[range];
vector<int> result;

bool isPrime(ll n)
{
	if (n == 1 || n == 0)	return false;

	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0)		return false;

	return true;
}

void solution()
{
	ll a, b;
	cin >> a >> b;

	for(ll i=a; i<=b; i++)
	{
		if(isPrime(i))
			cout<<i<<endl;
	}
	cout<<endl;
}


int main()
{
#ifdef ENABLE_DEBUG
	freopen("input.txt" , "r", stdin );
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	// sieve();
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
2
1 10
3 5

Output:
2
3
5
7

3
5
*/