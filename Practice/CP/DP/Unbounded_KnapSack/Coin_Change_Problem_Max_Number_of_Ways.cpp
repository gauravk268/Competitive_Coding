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


void coinChange()
{	
	vector<int> coin={1, 2, 3};		int count=5;	//5

	int n=coin.size();
	int dp[n+1][count+1];

	for(int i=0; i<=n; i++)
		dp[i][0]=1;

	for(int j=0; j<=count; j++)
		dp[0][j]=0;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=count; j++)
		{
			dp[i][j]=dp[i-1][j];

			if(coin[i-1]<=j)
				dp[i][j]=dp[i][j-coin[i-1]]+dp[i][j];
		}
	}

	cout<<dp[n][count]<<endl;

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
	    coinChange();
	}
	
	return 0;
}