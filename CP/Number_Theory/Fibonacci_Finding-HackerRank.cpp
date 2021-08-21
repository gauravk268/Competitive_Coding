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

ll M[3][3], start[3], I[3][3];

void matMul(ll A[3][3], ll B[3][3], int dim)
{
	ll res[dim + 1][dim + 1];

	for (int i = 1; i <= dim; i++)
	{
		for (int j = 1; j <= dim; j++)
		{
			res[i][j] = 0;
			for (int k = 1; k <= dim; k++)
			{
				ll x = (A[i][k] * B[k][j]) % MOD;
				res[i][j] = (res[i][j] + x) % MOD;
			}
		}
	}

	for (int i = 1; i <= dim; i++)
		for (int j = 1; j <= dim; j++)
			A[i][j] = res[i][j];
}

ll getFib(ll n)
{
	if (n <= 2)	return start[n];

	I[1][1] = I[2][2] = 1;
	I[1][2] = I[2][1] = 0;

	M[1][1] = 0;
	M[1][2] = M[2][2] = M[2][1] = 1;

	n = n - 1;
	while (n)
	{
		if (n % 2)		matMul(I, M, 2), n--;
		else		matMul(M, M, 2), n /= 2;
	}

	ll Fn = (start[1] * I[1][1] + start[2] * I[2][1]) % MOD;
	return Fn;
}

void solution()
{
	ll n;
	cin >> start[1] >> start[2] >> n;
	n++;

	cout << getFib(n) << endl;
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
Sample Input
8
2 3 1
9 1 7
9 8 3
2 4 9
1 7 2
1 8 1
4 3 1
3 7 5

Sample Output
3
85
25
178
8
8
3
44
*/
