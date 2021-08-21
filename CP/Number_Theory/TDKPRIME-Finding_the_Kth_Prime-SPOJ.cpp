#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x) 	 cout<<#x<<"="<<x<<endl
#define range 90000001

// #define ENABLE_DEBUG

bool ar[range];
vector<int> result;

void sieve()
{
	ar[0] = ar[1] = true;
	for (int i = 2; i * i <= range; i++)
	{
		if (!ar[i])
		{
			for (int j = i * i; j <= range; j += i)
				ar[j] = true;
		}
	}

	for (int i = 2; i <= range; i++)
		if (!ar[i])		result.push_back(i);
}

void solution()
{
	int value;
	cin >> value;

	cout << result[value - 1] << endl;
}

int main()
{
#ifdef ENABLE_DEBUG
	freopen("input.txt" , "r", stdin );
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();
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
7
1
10
100
1000
10000
100000
1000000

Output:
2
29
541
7919
104729
1299709
15485863
*/