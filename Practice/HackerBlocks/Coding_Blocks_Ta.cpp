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

// #define ENABLE_DEBUG

/*
Rohan is preparing for his interview for the position of ta at Coding Blocks. He doesn't have much time to prepare, so he will mug up the solution to the problems that he is unable to solve. He came across one problem for which he couldn't find the solution. As he doesn't have much time, so he asked you for the solution and during the time you are solving the problem, he can do some other problem. The problem is:
Given n dice each with m faces, numbered from 1 to m.Find the number of different ways to get x as the sum of values on all the dice.
Can you help him?
As the number can be large print it modulo 10^9+7.

Input Format
The first line contains three integers n ( the number of dice) , m (the number of face of each dice) and x (the sum to get).

Constraints
1 <= n,m <=50
1 <=x <= 500

Output Format
Print a single integer equal to the number of ways to get sum as x modulo 10^9+7.
*/

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