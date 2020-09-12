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

vector<int> ar[1001];
int vis[1001], dis[1001];

void dfs(int n, int d)
{
	vis[n] = 1;
	dis[n] = d;

	for (int child : ar[n])
	{
		if (!vis[child])
			dfs(child, dis[n] + 1);
	}
}

void solution()
{
	int n, q, a, b;
	cin >> n;

	for (int i = 0; i < n-1; i++)
		cin >> a >> b, ar[a].pb(b), ar[b].pb(a);

	dfs(1, 0);
	cin >> q;

	int ans = MOD, min_value = MOD;
	while (q--)
	{
		int girl;
		cin >> girl;

		if (dis[girl] < min_value)
			min_value = dis[girl], ans = girl;
		else if (dis[girl] == min_value && girl < ans)
			ans = girl;
	}

	cout << ans << endl;
	return;
}

int main()
{
#ifdef ENABLE_DEBUG
	freopen("input.txt" , "r", stdin );
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	// cin>>t;

	while (t--)
	{
		solution();
	}

	return 0;
}


/*
input
6
1 2
1 3
1 4
2 5
2 6
4
5
6
3
4

output
3

input
15
10 15
13 14
8 9
5 8
6 11
5 10
7 13
12 7
2 5
6 3
4 7
1 3
2 1
1 4
6
8
9
10
15
14
12

output
8
*/