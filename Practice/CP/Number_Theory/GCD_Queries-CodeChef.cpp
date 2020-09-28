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

int front[100005], back[100005], ar[100001];
int gcd(int a, int b)
{
	if (b == 0)	return a;
	return gcd(b, a%b);
}

void solution()
{
	int n, q;
	cin >> n >> q;

	front[0] = back[n + 1] = 0;

	for (int i = 1; i <= n; i++)	cin >> ar[i];

	for (int i = 1; i <= n; i++)    front[i] = gcd(front[i - 1], ar[i]);

	for (int i = n; i >= 1; i--)		back[i] = gcd(ar[i], back[i + 1]);

	while (q--)
	{
		int l, r;
		cin >> l >> r;

		cout << gcd(front[l - 1], back[r + 1])<<endl;
	}
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

	// cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}

/*
Input:
1
3 3
2 6 9
1 1
2 2
2 3

Output:
3
1
2
*/