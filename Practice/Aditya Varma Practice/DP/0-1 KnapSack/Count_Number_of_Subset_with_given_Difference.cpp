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


int countSubsetSum(vector<int> &value, int diff)
{
	int n=value.size();
	int range=accumulate(value.begin(), value.end(), 0);
	int temp=(range+diff)/2;

	int dp[n+1][temp+1];

	for(int i=0; i<=temp; i++)
		dp[0][i]=0;

	for(int i=0; i<=n; i++)
		dp[i][0]=1;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=temp; j++)
		{
			dp[i][j]=dp[i-1][j];

			if(value[i-1]<=j)
				dp[i][j]=dp[i-1][j-value[i-1]]+dp[i-1][j];
		}
	}

	return dp[n][temp];
}

void solve()
{	
	vector<int> value={1, 1, 2, 3};  int diff=1;	//3
	cout<<countSubsetSum(value, diff)<<endl;

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