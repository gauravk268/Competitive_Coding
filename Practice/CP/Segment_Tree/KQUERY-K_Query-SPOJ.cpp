#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define INF		MOD
#define deb(x) 	 cout<<#x<<"="<<x<<endl
#define showRunTime  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

#define f  first
#define s  second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

#define maxN 30001

// #define ENABLE_DEBUG

int ar[maxN];
vector<int> st[4 * maxN];

void printMerge(int n){
	for(int i=1; i<=4*n; i++)
	{
		for(auto value:st[i])
			cout<<value<<" ";
		cout<<endl;
	}
}

void merge(int si, int a, int b)
{
	int i = 0, j = 0;

	while (i < st[a].size() && j < st[b].size())
	{
		if (st[a][i] < st[b][j])		st[si].pb(st[a][i++]);
		else	st[si].pb(st[b][j++]);
	}

	while (i < st[a].size())	st[si].pb(st[a][i++]);
	while (j < st[b].size())	st[si].pb(st[b][j++]);
}

void build(int si, int ss, int se)
{
	if (ss == se)
	{
		st[si].pb(ar[ss]);
		return;
	}

	int mid = (ss + se) / 2;
	build(2 * si, ss, mid);
	build(2 * si + 1, mid + 1, se);

	merge(si, 2 * si, 2 * si + 1);
}

int query(int si, int ss, int se, int qs, int qe, int k)
{
	if (ss > qe || se < qs)		return 0;
	if(ss >=qs && se <=qe)
		return (st[si].end() - upper_bound(st[si].begin(), st[si].end(), k));

	int mid=(ss+se)/2;
	int l = query(2*si, ss, mid, qs, qe, k);
	int r = query(2*si+1, mid+1, se, qs, qe, k);

	return l+r;
}

void solution()
{
	memset(ar, 0, sizeof(ar));
	int n;	cin >> n;

	for (int i = 1; i <= n; i++)	cin >> ar[i];
	build(1, 1, n);

	int q;	cin>>q;
	while (q--)
	{
		int a, b, c;	cin >> a >> b >> c;
		cout << query(1, 1, n, a, b, c) << endl;
	}
}

int main()
{
#ifdef ENABLE_DEBUG
	freopen("stdin.txt", "r", stdin);
	freopen("stdout.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int t = 1;
	// cin>>t;

	while (t--)
	{
		solution();
	}

	showRunTime;
	return 0;
}

/*
Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 

Output
2
0
3 
*/