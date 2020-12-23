#include<bits/stdc++.h>
using namespace std;

#define ll     long long
#define endl   "\n"
#define MOD    1000000007
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

vector<int> ar[100001];
int vis[100001];
int cc_size;

void dfs(int node)
{
	vis[node]=1;
	cc_size++;

	for(int child:ar[node])
	{
		if(!vis[child])
		{
			dfs(child);
		}
	}
}

void solution()
{
	int n, m, a, b;

	cin >> n >> m;

	for(int i=1; i<=n; i++)	ar[i].clear(), vis[i]=0;

	while(m--)
		cin>>a>>b, ar[a].pb(b), ar[b].pb(a);

	int cc=0;
	ll ways=1;
	for(int i=1; i<=n; i++)
	{
		if(!vis[i])
		{
		    cc_size=0;
		    
			dfs(i), cc++;
			ways=(ways*cc_size)%MOD;
		}
	}

	cout<<cc<<" "<<ways<<endl;
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
	cin >> t;

	while (t--)
	{
		solution();
	}

	return 0;
}


/*
Input:
3
4 2
1 2
2 3
5 3
1 2
2 3
1 3
6 3
1 2
3 4
5 6

Output:
2 3
3 3
3 8
*/ 