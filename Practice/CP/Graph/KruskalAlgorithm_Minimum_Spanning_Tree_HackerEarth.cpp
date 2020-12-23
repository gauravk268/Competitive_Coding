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


struct edge
{
	int a, b, w;
};

bool comp(edge a, edge b)
{
	return a.w < b.w;
}

edge ar[100001];
int par[10001];

int find(int a)
{
	if(par[a]== -1)	return a;
	return par[a]=find(par[a]);
}

void merge(int a, int b)
{
	par[a]=b;
}

void solution()
{
	int n, m, a, b;
	cin>>n>>m;

	memset(par, -1, sizeof(par));

	for(int i=0; i<m; i++)
	{
		cin>>ar[i].a>>ar[i].b>>ar[i].w;
	}

	int sum=0;
	sort(ar, ar+m, comp);

	for(int i=0; i<m; i++)
	{
		a=find(ar[i].a);
		b=find(ar[i].b);

		if(a!=b)
		{
			sum+=ar[i].w;
			merge(a, b);
		}
	}

    cout<<sum<<endl;
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
		solution();
	}

	return 0;
}

/*
Input
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6

Output
19
*/