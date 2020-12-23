#include<bits/stdc++.h>
using namespace std;

// MACROS-----------------------------------------------------------------------

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

// MACROS END ------------------------------------------------------------------

// GLOBAL VARIABLE -------------------------------------------------------------

vector<int> adj[4], visited(4, 0);

// GLOBAL VARIABLE END ---------------------------------------------------------


void dfs(int v)
{
    cout<<v<<" -> ";
    visited[v]=1;
    
    for(int child=0; child<adj[v].size(); child++)
    {
        if(not visited[child])
            dfs(child);
    }
}


void solve()
{	
	// Create a graph given in the above diagram
	int numEdges=4;

	while(numEdges--)
	{
		int a,b;
		cin>>a>>b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=0; i<4; i++)
	    if(not visited[i])
	        dfs(i);

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