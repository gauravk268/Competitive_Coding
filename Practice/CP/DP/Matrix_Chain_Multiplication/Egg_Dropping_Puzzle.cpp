 #include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x) 	 cout<<#x<<"="<<x<<endl
#define fLoop(n) for(int i=1; i<=n; i++)

#define f  first
#define s  second
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef deque<int>  di;
typedef stack<int>  si;
typedef pair<int, int> 		 pi;
typedef tuple<int, int, int> ti;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;


void printVector(vector<int> &value) { for (auto temp : value) 
	{ cout << temp << " "; } cout << "\n";}

// #define ENABLE_DEBUG

int dp[1001][1001];
int memoizedEggDrop(int e, int f)
{
	if(e==1 || f==0 || f==1)
		return f;
		
	if(dp[e][f]!= -1)
        return dp[e][f];
        
	int minCase=INT_MAX, temp;

	for(int i=1; i<=f; i++)
	{
	    int left, right;
	    
	    left = (dp[e-1][i-1]!= -1)? dp[e-1][i-1]:memoizedEggDrop(e-1, i-1);
        right = (dp[e][f-i]!= -1)? dp[e][f-i]:memoizedEggDrop(e, f-i);
	        
		temp=1+max(left, right);
 
		if(minCase>temp)	minCase=temp;
	}
	
	return dp[e][f]=minCase;
}

int eggDrop(int e, int f)
{
	if(e==1 || f==0 || f==1)
		return f;

	int minCase=INT_MAX, temp;

	for(int i=1; i<=f; i++)
	{
		temp=1+max(eggDrop(e-1, i-1), eggDrop(e, f-i));
 
		if(minCase>temp)	minCase=temp;
	}
	return minCase;
}

void solution()
{
    
	// int es=2, fs=10;	//4
	// int es=3, fs=6;	//3

	cout<<"Resursion: "<<eggDrop(es, fs)<<endl;
	cout<<"Memoized: "<<memoizedEggDrop(es, fs)<<endl;
}

int main()
{
#ifdef ENABLE_DEBUG
	freopen("input.txt" , "r", stdin );
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin>>t;

	while (t--)
	{
	    memset(dp, -1, sizeof(dp));
		solution();
	}

	return 0;
}