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

ll power(ll a, ll n, ll d)
{
	ll res = 1;
	while (n)
	{
		if (n % 2)
		{
			res = ((res % d) * (a % d)) % d;
			n--;                     
		}
		else
		{
			a = ((a % d) * (a % d)) % d;
			n /= 2;
		}
	}

	return res%d;
}

ll gcd(ll a, ll b, ll n)
{
	if (a == b)
	{
		return (power(a, n, MOD) + power(b, n, MOD)) % MOD;
	}

	ll candidate = 1, num = a - b;
	for (ll i = 1; i * i <= num; i++)
	{
		if (num % i == 0 )
		{
			ll tmp = (power(a, n, i) + power(b, n, i)) % i;

			if (tmp == 0)	candidate = max(candidate, i);

			tmp = (power(a, n, num / i) + power(b, n, num / i)) % (num / i);

			if (tmp == 0)	candidate = max(candidate, num / i);
		}
	}

	return candidate%MOD;
}

void solution()
{
	ll a, b, n;
	cin >> a >> b >> n;

	cout << gcd(a, b, n) << endl;
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
10 1 1
9 1 5

Example Output
1
2
*/