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

void printVector(vector<int> &value){ for(auto temp:value){ cout<<temp<<" "; } cout<<"\n";}

// #define ENABLE_DEBUG


int countSubsetSum(vector<int> &value, int sum)
{
    int n=value.size();
    
	vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

	for(int i=0; i<=n; i++)
		dp[i][0]=1;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=sum; j++)
		{
			if(value[i-1]<=j)		dp[i][j]=dp[i-1][j-value[i-1]]+dp[i-1][j];
			else	dp[i][j]=dp[i-1][j];
		}
	}

	return dp[n][sum];
}

void solve()
{	
	// vector<int> value={2, 3, 5, 6, 8, 10}; 	int sum=10;		// 3;
	// vector<int> value={1, 2, 3, 3}; 	int sum=6;		// 3;
	// vector<int> value={1, 1, 1, 1}; 	int sum=1;		// 4;
	vector<int> value={10, 1, 2, 7, 6, 1, 5}; 	int sum=8;		// 4;
	
	cout<<"CountSubsetSum: "<<countSubsetSum(value, sum)<<endl;

    return;
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
		cout<<"Result: \n";
	    solve();
	}
	
	return 0;
}