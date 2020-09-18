#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define llu		 unsigned long long int
#define endl     "\n"
#define MOD      1000000007
#define deb(x) 	 cout<<#x<<"="<<x<<endl

#define f  first
#define s  second
#define pb push_back
#define mp make_pair

/*

Nikita is making a colour full Graph as a birthday gift for her boyfriend, a fellow programmer! She has n integers. She wants to draw an undirected connected graph with N edge Each node is shaded in either red or black color. We define nr to be the number of red nodes and nb to be the number of black nodes. No 2 adjacent nodes have the same color.

Last Night before the birthday party, Nikita's mischievous little brother removed the last n-2 number. She is really disappointed because she lost the last n-2 number. She calls you because you are her best friend. You suggest giving an array on the birthday. Nikita has only 2 numbers among these n numbers. These numbers are the first 2 numbers in n number. If she gifts simply these 2 numbers as an array, then her boyfriend will be disappointed. Nikita never wants her boyfriend to be disappointed at a birthday party. You suggest making it a magical array. property of magical:

The shortest array such that bitwise xor of its elements is the first number and the sum of its elements is the second number . Can you help her to build this array Because you're her best friend

Input Format
The only line contains 2 numbers (which denote First and second number ).

Constraints
range of these two number (0≤p,q≤10^18)

Output Format
If there's no array that satisfies the condition, print the difference of 2 numbers(absolute difference ) Otherwise:print an integer n representing the length of the desired array. The next line should contain n positive integers, the array itself. Array must be Sorted

*/

// #define ENABLE_DEBUG


void func(llu s, llu x)
{
	if(s==0)
		cout<<0<<endl;

	if(x>s || s%2 != x%2)
	{
		if(s>x)	cout<<s-x<<endl;
		else cout<<x-s<<endl;

		return;
	}

	if(s==x)
	{
		cout<<1<<endl<<s<<endl;
		return;
	}

	int mid=(s-x)/2;

	if(s & x)
	{
		cout<<3<<endl;
		if(x<mid)	cout<<x<<" "<<mid<<" "<<mid<<endl;
		else 	cout<<mid<<" "<<mid<<" "<<x<<endl;

		return;
	}
	
	cout<<2<<endl;
	cout<<mid<<" "<<x+mid<<endl;
	return;
}


void solution()
{
	llu sum, xorr;
	cin >> xorr >>sum;

	func(sum, xorr);
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
	// cin>>t;

	while (t--)
	{
		solution();
	}

	return 0;
}

/*
Input
4 10

Output
2
3 7

Input
2 4

Output
2
3 1

Input
5 8

Output
3
*/