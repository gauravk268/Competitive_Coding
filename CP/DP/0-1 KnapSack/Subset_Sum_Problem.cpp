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
 

bool dpSubsetSum(vector<int> &v, int sum)
{
	int n=v.size();

	bool dp[n+1][sum+1];

	for(int i=0; i<=sum; i++)
		dp[0][i]=false;

	for(int i=0; i<=n; i++)
		dp[i][0]=true;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=sum; j++)
		{
			if(v[i-1]<=j)		dp[i][j]=(dp[i-1][j-v[i-1]] || dp[i-1][j]);
			else	dp[i][j]=dp[i-1][j];
		}
	}

    if(dp[n][sum])  return true;
	else	return false;
}

void solve()
{	
	// vector<int> v={7, 2, 3, 10, 8, 12};		int sum=43;     //false
	// vector<int> v = {3, 34, 4, 12, 5, 2};	int sum = 9;	//true
	vector<int> v = {3, 34, 4, 12, 5, 2};	int sum = 30;	//false

	cout<<"DP: "<<dpSubsetSum(v, sum)<<endl;
	
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
	   // dpSubsetSum();	
	}
	
	return 0;
}