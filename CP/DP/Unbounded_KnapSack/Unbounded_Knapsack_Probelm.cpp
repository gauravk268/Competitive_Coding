#include<bits/stdc++.h>
using namespace std;

#define ll     long long
#define endl   "\n"
#define MOD    1e9+7
#define deb(x) cout<<#x<<"="<<x<<endl

#define f  first
#define s  second
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef deque<int>  di;
typedef stack<int>  si;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef pair<int, int> 		 pi;
typedef tuple<int, int, int> ti;

// #define ENABLE_DEBUG


int dpKnapsack(vector<int> &wt, vector<int> &val, int w, int n)
{
	vector<vector<int>> dp(n+1, vector<int>(w+1));

	for(int i=0; i<n+1; i++)
	{
		for(int j=0; j<w+1; j++)
		{
			if(i==0 || j==0)	dp[i][j]=0;
			else if(wt[i-1]<=j)	dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
			else	dp[i][j]=dp[i-1][j];
		}
	}

	return dp[n][w];
}

int main() 
{
	#ifdef ENABLE_DEBUG
		freopen("input.txt" , "r", stdin );
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
	// cin>>t;

	while(t--)
	{
		cout<<"Result:\n";
	   vector<int> wt={1, 3, 4, 5}, val={2, 4, 5, 7}; int w=9, n=4;
	    // vector<int> wt={10, 20, 30}, val={60, 100, 120}; int w=50, n=3;

	    cout<<"DP: "<<dpKnapsack(wt, val, w, n)<<endl;	
	}
	
	return 0;
}