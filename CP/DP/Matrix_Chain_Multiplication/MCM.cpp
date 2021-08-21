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


int recursiveMCM(vector<int> &value, int i, int j)
{	
	if(i>=j)	return 0;
	int min=INT_MAX, temp;

	for(int k=i; k<=j-1; k++)
	{
		temp=recursiveMCM(value, i, k)+recursiveMCM(value, k+1, j)+(value[i-1]*value[k]*value[j]);

		if(temp<min)	min=temp;
	}

	return min;
}

int dp[1001][1001];	//values can be changed as per limit given in the problem

int memoizedMCM(vector<int> &value, int i, int j)
{
	if(i>=j)	return 0;
	int min=INT_MAX, temp;

	if(dp[i][j]!= -1)	return dp[i][j];
	else
	{
		for(int k=i; k<=j-1; k++)
		{
			temp=recursiveMCM(value, i, k)+recursiveMCM(value, k+1, j)+(value[i-1]*value[k]*value[j]);

			if(temp<min)	min=temp;
		}
	}

	return dp[i][j]=min;
}

int main() 
{
	#ifdef ENABLE_DEBUG
		freopen("input.txt" , "r", stdin );
		freopen("output.txt", "w", stdout);
	#endif
	
	memset(dp, -1, sizeof(dp));

	int t=1;
	// cin>>t;

	while(t--)
	{
	   // vector<int> value={40, 20, 30, 10, 30};		//26000
	   // vector<int> value={10, 20, 30, 40, 30};		//30000
	    vector<int> value={10, 20, 30};				//6000

	    cout<<"Recursion: "<<recursiveMCM(value, 1, value.size()-1)<<endl;
	    cout<<"Memoized: "<<memoizedMCM(value, 1, value.size()-1)<<endl;
	}
	
	return 0;
}