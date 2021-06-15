#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define max		 INT_MAX
#define deb(x) 	 cout<<#x<<"="<<x<<endl

#define f  first
#define s  second
#define pb push_back
#define mp make_pair


int dp[55][555];
int func(int numDice, int numFace, int sum)
{
	if (sum == 0 && numDice == 0)
		return 1;

	if (sum < 0 || numDice == 0)
		return 0;

	if (dp[numFace][sum] != -1)	return dp[numFace][sum];

	int ans = 0;
	for (int i = 1; i <= numFace; i++)
	{
		ans += func(numDice - 1, numFace, sum - i);
	}

	return dp[numDice][sum] = ans;
}

void solution()
{
	memset(dp, -1, sizeof(dp));
	int numDice, numFace, sum;
	cin >> numDice >> numFace >> sum;

	cout << func(numDice, numFace, sum) << endl;
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
	// cin>>t;

	while (t--)
	{
		solution();
	}

	return 0;
}

/*

Input
3 6 18

Output
1

Input
3 6 12

Output
25
*/