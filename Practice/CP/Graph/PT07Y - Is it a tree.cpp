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

vector<int> ar[100001], parent(100001, -1);
int vis[100001];
bool flag=true;

void dfs(int n)
{
	vis[n]=1;
	
	for(int child:ar[n])
	{
		if(!vis[child])
			dfs(child), (parent[child]!= -1)?flag=false:parent[child]=n;
	}
}

void solution()
{	
	int n, m, a, b;
	cin>>n>>m;

	for(int i=1; i<=m; i++)
		cin>>a>>b, ar[a].pb(b), ar[b].pb(a);
		
	int cc=0;

	for(int i=1; i<=n; i++)
		if(!vis[i])
			dfs(i), cc++;

	if(cc!=1 || m!= n-1)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
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
	    solution();
	}
	
	return 0;
}

/*
Input:
3 2
1 2
2 3

Output:
YES
*/