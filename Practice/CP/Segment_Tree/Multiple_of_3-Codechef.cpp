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

#define maxN 100001

// #define ENABLE_DEBUG

class node
{
public:
	int a, b, c;
};

int ar[maxN], lazy[4 * maxN];
node st[4 * maxN];

void build(int si, int ss, int se)
{
	if (ss == se)
	{
		st[si].a = 1;
		st[si].b = 0;
		st[si].c = 0;

		return;
	}

	int mid = (ss + se) / 2;
	build(2 * si, ss, mid);
	build(2 * si + 1, mid + 1, se);

	st[si].a = st[2 * si].a + st[2 * si + 1].a;
	st[si].b = st[2 * si].b + st[2 * si + 1].b;
	st[si].c = st[2 * si].c + st[2 * si + 1].c;
}

void shift(int si)
{
	int a = st[si].c;
	st[si].c = st[si].b;
	st[si].b = st[si].a;
	st[si].a = a;
}

int query(int si, int ss, int se, int qs, int qe)
{
	if (lazy[si] != 0)
	{
		int add = lazy[si];
		lazy[si] = 0;
		if (ss != se)
		{
			lazy[2 * si] += add;
			lazy[2 * si + 1 ] += add;
		}

		add %= 3;
		for (int i = 0; i < add; i++)
		{
			shift(si);
		}
	}

	if (ss > qe || se < qs)		return 0;
	if (ss >= qs && se <= qe)	return st[si].a;

	int mid=(ss+se)/2;
	int l=query(2*si, ss, mid, qs, qe);
	int r=query(2*si+1, mid+1, se, qs, qe);

	return l+r;
}

void update(int si, int ss, int se, int qs, int qe)
{
	if (lazy[si] != 0)
	{
		int add = lazy[si];
		lazy[si] = 0;
		if (ss != se)
		{
			lazy[2 * si] += add;
			lazy[2 * si + 1 ] += add;
		}

		add %= 3;
		for (int i = 0; i < add; i++)
		{
			shift(si);
		}
	}

	if (ss > qe || se < qs)		return;
	if (ss >= qs && se <= qe)
	{
		shift(si);
		if(ss != se)
		{
			lazy[2 * si] ++;
			lazy[2 * si + 1 ] ++;
		}
		return;
	}

	int mid=(ss+se)/2;
	update(2*si, ss, mid, qs, qe);
	update(2*si+1, mid+1, se, qs, qe);

	st[si].a = st[2 * si].a + st[2 * si + 1].a;
	st[si].b = st[2 * si].b + st[2 * si + 1].b;
	st[si].c = st[2 * si].c + st[2 * si + 1].c;
}


void solution()
{
	memset(ar, 0, sizeof(ar));
	int n, q;	cin >> n >> q;

	build(1, 1, n);
	while (q--)
	{
		int a, b, c;	cin >> a >> b >> c;
		b++, c++;

		switch (a)
		{
		case 0:
			update(1, 1, n, b, c);
			break;
		case 1:
			cout << query(1, 1, n, b, c) << endl;
			break;
		}
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
Sample Input :
4 7
1 0 3
0 1 2
0 1 3
1 0 0
0 0 3
1 3 3
1 0 3

Sample Output :
4
1
0
2
*/