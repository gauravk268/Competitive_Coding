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


int minSubsetSumDiff(vector<int> &value)
{
	int n=value.size();
	int range=accumulate(value.begin(), value.end(), 0);
        
    vector<int> result;
    bool dp[n+1][range+1];

    for(int i=0; i<=range; i++)
    	dp[0][i]=false;

    for(int i=0; i<=n; i++)
    	dp[i][0]=true;

    for(int i=1; i<=n; i++)
    {
    	for(int j=1; j<=range; j++)
    	{
    		dp[i][j]=dp[i-1][j];

    		if(value[i-1]<=j)
    			dp[i][j] |=dp[i-1][j-value[i-1]];
    	}
    }

    int diff=INT_MAX;

	for(int i=range/2; i>=0; i--)
	{
		if(dp[n][i]==true)
		{
			diff=range-2*i;
			break;
		}
	}

	return diff;
}

void solve()
{	
	vector<int> value={1, 5, 11, 6}; 	//1
	cout<<minSubsetSumDiff(value)<<endl;

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