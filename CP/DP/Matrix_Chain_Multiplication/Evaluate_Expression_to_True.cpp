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


int solve(string &value, int i, int j, bool flag)
{	
	if(i>j)     return 1;

	if(i==j)
	{
		if(flag)
			return (value[i]=='T');
		else
    		return (value[i]=='F');
	}

	int ans=0;
	for(int k=i+1; k<=j; k+=2)
	{
		int lT = solve(value, i, k-1, true);
		int lF = solve(value, i, k-1, false);
		int rT = solve(value, k+1, j, true);
		int rF = solve(value, k+1, j, false);

		if(value[k]=='|')
		{
			if(flag)	ans+= (lT*rF)+(lT*rT)+(lF*rT);
			else 	ans+=(lF*rF);
		}
		else if(value[k]=='&')
		{
			if(flag)	ans+= (lT*rT);
			else 	ans+=(lT*rF)+(lF*rT)+(lF*rF);
		}
		else if(value[k]=='^')
		{
			if(flag)	ans+= (lT*rF)+(lF*rT);
			else 	ans+=(lT*rT)+(lF*rF);
		}
	}

	return ans;
}

int dp[200][200][2];
int memoizedSolve(string &value, int i, int j, int flag)
{	
    if(i>j)		return 1;

	if(i==j)
	{
		if(flag)
			return value[i]=='T';
		else
    		return value[i]=='F';
	}
	
	if(dp[i][j][flag]!= -1)   return dp[i][j][flag];
	

	int ans=0;
	for(int k=i+1; k<j; k+=2)
	{
		int lT = solve(value, i, k-1, 1);
		int lF = solve(value, i, k-1, 0);
		int rT = solve(value, k+1, j, 1);
		int rF = solve(value, k+1, j, 0);

		if(value[k]=='|')
		{
			if(flag)	ans+= (lT*rF)+(lT*rT)+(lF*rT);
			else 	ans+=(lF*rF);
		}
		else if(value[k]=='&')
		{
			if(flag)	ans+= (lT*rT);
			else 	ans+=(lT*rF)+(lF*rT)+(lF*rF);
		}
		else if(value[k]=='^')
		{
			if(flag)	ans+= (lT*rF)+(lF*rT);
			else 	ans+=(lT*rT)+(lF*rF);
		}
	}

	return dp[i][j][flag]=ans;
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

	// string value="T|F&T^F";     //5
    // string value="T|F";         //1
    // string value="T^T^F";       //0
    string value="T^T^T^F|F&F^F|T^F^T";   //2539  

	while(t--)
	{
	    cout<<"Recursion: "<<solve(value, 0, value.length()-1, 1)<<endl;
	    cout<<"Memoized: "<<memoizedSolve(value, 0, value.length()-1, 1);
	}
	
	return 0;
}