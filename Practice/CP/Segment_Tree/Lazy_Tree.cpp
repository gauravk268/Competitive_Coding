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

#define maxN 10001

// #define ENABLE_DEBUG

int st[4*maxN], lazy[4*maxN], ar[maxN];
void buildTree(int si, int ss, int se)
{
	if (ss == se)	st[si] = ar[ss];

	int mid = (ss + se) / 2;
	buildTree(2 * si, ss, mid);
	buildTree(2 * si + 1, mid + 1, se);

	st[si] = st[2 * si]+st[2 * si + 1];
}

int query(int si, int ss, int se, int qs, int qe)
{
	if(lazy[si] != 0)
	{
		int dx=lazy[si];
		lazy[si]=0;
		st[si]+=dx*(se-ss+1);

		if(ss != se)
			lazy[2*si]+=dx, lazy[2*si+1]+=dx;
	}

	if (qe < ss || qs > se)	return INF;
	if (ss >= qs && se <= qe)	return st[si];

	int mid = (ss + se) / 2;
	int l = query(2 * si, ss, mid, qs, qe);
	int r = query(2 * si + 1, mid + 1, se, qs, qe);

	return l+r;
}

void updateST(int si, int ss, int se,int qs, int qe, int val)
{
	if(lazy[si] != 0)
	{
		int dx=lazy[si];
		lazy[si]=0;
		st[si]+= dx*(se-ss+1);

		if(ss != se)
			lazy[2*si]+=dx, lazy[2*si+1]+=dx;
	}

	if(ss > qe || se <qs)	return;

	if(ss>=qs && se<=qe)
	{
		int dx=(se-ss+1)*val;
		st[si]+=dx;

		if(ss != se)
			lazy[2*si]+=val, lazy[2*si +1 ]+=val;
		return;
	}

	int mid = (ss + se) / 2;
	updateST(2 * si, ss, mid, qs, qe, val);
	updateST(2 * si + 1, mid + 1, se, qs, qe, val);

	st[si] = st[2 * si]+ st[2 * si + 1];
}

void solution()
{
		
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