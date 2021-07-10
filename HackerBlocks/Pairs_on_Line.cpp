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

/*
You are given a linear equation y = mx + c, and an array A of n elements. Count the number of ordered pairs (i,j) where i!=j, such that point (Ai, Aj) satisfies the given linear equation.

Input Format
First line contains 3 integers, n, m and c. Next line contains n integers, denoting the elements of array A.
*/

void solution()
{
	ll n, m, c;
	cin>>n>>m>>c;

	unordered_set<int> s;
	unordered_map<ll, ll> v;
	
	for(int i=0; i<n; i++)
	{
		ll temp;
		cin>>temp;

		s.insert(temp), v[temp]++;
	}

	ll count=0;
	for(auto i=s.begin(); i!=s.end(); i++){
		ll x=*i;
		ll y=m*x+c;

		if(s.find(y)!=s.end())
		{
			if(v[x]==1)	count+=v[y];
			else	count+=(v[y]*v[x]);

			if(y == x)	count--;
		}
	}

	cout<<count<<endl;
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
5 1 1
1 2 3 4 2

Output
5

Input
6 2 1
1 2 3 4 2 5

Output
3
*/