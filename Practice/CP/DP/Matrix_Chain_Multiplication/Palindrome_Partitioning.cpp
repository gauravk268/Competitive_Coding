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

bool isPalindrome(string &value, int i, int j)
{
	while(i<=j)
	{
		if(value[i]!=value[j])
			return false;

		i++;
		j--;
	}

	return true;
}

int palindromePartition(string &value, int i, int j)
{	
	if(i>j || isPalindrome(value, i, j))	return 0;
	int minValue=INT_MAX, temp=0;

	for(int k=i; k<=j-1; k++)
	{
		temp=1+palindromePartition(value, i, k)+palindromePartition(value, k+1, j);

	    if(temp<minValue)   minValue=temp;
	}

	return minValue;
}

int dp[1001][1001];
int memoizedPartition(string &value, int i, int j)
{
	if(i>j || isPalindrome(value, i, j))	return 0;
	int minValue=INT_MAX, temp=0;

	if(dp[i][j]!= -1)	return dp[i][j];
	else
	{
		for(int k=i; k<=j-1; k++)
		{
			temp=1+palindromePartition(value, i, k)+palindromePartition(value, k+1, j);

		    if(temp<minValue)   minValue=temp;
		}
	}

	return dp[i][j]=minValue;
}

int mostOptimizedPartition(string &value, int i, int j)
{
	if(i>j || isPalindrome(value, i, j))	return 0;
	int minValue=INT_MAX, temp=0;

	if(dp[i][j]!= -1)	return dp[i][j];
	else
	{
		for(int k=i; k<=j-1; k++)
		{
			int left = (dp[i][k]!= -1)?dp[i][k]:palindromePartition(value, i, k);
			int right = (dp[k+1][j]!= -1)?dp[k+1][j]:palindromePartition(value, k+1, j);

			temp=1+left+right;

		    if(temp<minValue)   minValue=temp;
		}
	}

	return dp[i][j]=minValue;
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
	   	string value="ababbbabbababa";	//3
	   	// string value="abbac";			//1
	   	// string value="abcde";			//4
	   	// string value="aaaa";			//0

	    cout<<"Recursive: "<<palindromePartition(value, 0, value.length()-1)<<endl;
	    cout<<"Memoized: "<<memoizedPartition(value, 0, value.length()-1)<<endl;
	    cout<<"Most Optimized: "<<mostOptimizedPartition(value, 0, value.length()-1)<<endl;
	    
	}
	
	return 0;
}