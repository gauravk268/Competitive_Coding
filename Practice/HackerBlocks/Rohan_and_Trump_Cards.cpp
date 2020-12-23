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
	int n;
	cin>>n;

	ll temp, result=0;
	priority_queue <ll, vector<ll>, greater<ll>> h;
	while(n--)	 cin>>temp, h.push(temp);

	while(h.size()!= 1)
	{
		ll a=h.top();	h.pop();
		ll b=h.top();	h.pop();

		result+=(a+b);
		h.push(a+b);
	}

	cout<<result<<endl ;
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
	cin>>t;

	while (t--)
	{
		solution();
	}

	return 0;
}

/*
Sample Input
1
4
1 2 3 4
Sample Output
19
Explanation
4 packs, each containing 1, 2, 3 and 4 cards respectively.Adding 1 + 2 in a new collection box takes 3 seconds.Adding 3 + 3 in a new collection box takes 6 seconds.Adding 4 + 6 in a new collection box takes 10 seconds.Hence total time taken is 19 seconds. There could be other combinations also, but overall time does not go below 19 seconds
*/