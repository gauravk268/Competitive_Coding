#include<bits/stdc++.h>
using namespace std;

// #define ENABLE_DEBUG

/* A professional robber planning to rob houses along a street. Each
house has a certain amount of money stashed, the only constraint
stopping him from robbing each of them is that adjacent houses have
security system connected and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money he can rob tonight without alerting the police.

Input Format
First line contains integer t as number of testcases. Second line contains integer n as size of array. Third line contains a single integer as element of array.
*/


int func(vector<int> &value, int n)
{
	if (n == 0)	return 0;
	if (n == 1)	return value[0];
	if (n == 2)	return max(value[0], value[1]);

	int t[n];
	t[0] = value[0];
	t[1] = max(value[0], value[1]);

	for (int i = 2; i < n; i++)
	{
		t[i] = max(value[i] + t[i - 2], t[i - 1]);
	}

	return t[n - 1];
}

void solution()
{
	int n;
	cin >> n;

	vector<int> value(n);
	for (int i = 0; i < n; i++)	cin >> value[i];

	cout << func(value, n) << endl;
	return;
}

int main()
{
#ifdef ENABLE_DEBUG
	freopen("input.txt" , "r", stdin );
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;

	while (t--)
	{
		// cout<<"Result: \n";
		solution();
	}

	return 0;
}

/*
Input
5
4
1 2 3 1
5
1 2 3 1 7
7
6 7 1 3 8 2 4
6
1 2 3 1 7 1
5
5 3 4 11 2


Output
4
11
19
11
16
*/