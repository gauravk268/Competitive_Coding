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

void printVector(vector<int> &value) { for (auto temp : value) { cout << temp << " "; } cout << "\n";}

// #define ENABLE_DEBUG

vi ar[2001];
int vis[2001], col[2001];

bool dfs(int node, int c)
{
	vis[node] = 1;
	col[node] = c;

	for(int child:ar[node])
	{
		if(vis[child]==0)
		{
		    bool res=dfs(child, c^1);
			if(res==false)
			    return false;
		}
		else    
		    if(col[node]==col[child])
		        return false;
	}

	return true;
}

void solution()
{
	int n, m, a, b;
	
	string right = "No suspicious bugs found!",
	       wrong = "Suspicious bugs found!";

	cin >> n >> m;	
	
	for(int i=1; i<=n; i++) ar[i].clear(), vis[i]=0;
	
	for(int i=1; i<=m; i++)
	    cin >> a >> b, ar[a].pb(b), ar[b].pb(a);
	    
	bool flag=true;
	for(int i=1; i<=n; i++)
	{
	    if(vis[i]==0)
	    {
	        bool res=dfs(i, 0);
	        if(res==false)
	            flag=false;
	    }
	}

	if(flag==true)
	    cout<<right<<endl;
	else
	    cout<<wrong<<endl;
}

int main()
{
    #ifdef ENABLE_DEBUG
    	freopen("input.txt" , "r", stdin );
    	freopen("output.txt", "w", stdout);
    #endif

// 	ios_base::sync_with_studio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;

	for(int i=1; i<=t; i++)
	{
		cout << "Scenario #" << i << ":" << endl;
		solution();
	}

	return 0;
}

/*
Input:
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4

Output:
Scenario #1:
Suspicious bugs found!
Scenario #2:
No suspicious bugs found!
*/