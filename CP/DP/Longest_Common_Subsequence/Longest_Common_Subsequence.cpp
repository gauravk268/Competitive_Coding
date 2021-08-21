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


int recursiveLCS(string a, string b, int m, int n)
{	
    if(m==0 || n==0)    return 0;
    
	int result=0;

	if(a[m-1]==b[n-1])
	{
		result++;
		result+=recursiveLCS(a, b, m-1, n-1);
	}
	else
	{
		result+=max(recursiveLCS(a, b, m-1, n), recursiveLCS(a, b, m, n-1));
	}

	return result;
}


vector<vector<int>> t(10001, vector<int>(10001, -1));	
//size can be set as per constraints of the problem

int memoizedLCS(string a, string b, int m, int n)
{	
    if(m==0 || n==0)    return 0;
    if(t[m][n]!= -1)	return t[m][n];

	int result=0;

	if(a[m-1]==b[n-1])
	{
		result++;
		result+=memoizedLCS(a, b, m-1, n-1);
	}
	else
	{
		result+=max(memoizedLCS(a, b, m-1, n), memoizedLCS(a, b, m, n-1));
	}

	return t[m][n]=result;
}

int dpLCS(string a, string b, int m, int n)
{	
	int dp[m+1][n+1];

	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
		}
	}

	return dp[m][n];
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

	    // string a="abcdef", b="abcegf";	int m=a.length(), n=b.length();		//5
	    string a="AGGTAB", b="GXTXAYB";	int m=a.length(), n=b.length();		//4

	    cout<<"Recursive: "<<recursiveLCS(a, b, m, n)<<endl;
	    cout<<"Memoized: "<<memoizedLCS(a, b, m, n)<<endl;
	    cout<<"DP: "<<dpLCS(a, b, m, n)<<endl;
	}
	
	return 0;
}