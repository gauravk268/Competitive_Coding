#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x) 	 cout<<#x<<"="<<x<<endl
#define showRunTime  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

#define f  first
#define s  second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

// #define ENABLE_DEBUG
const int maxN = 100001;
int ar[maxN];
pair<int, int> st[4 * maxN];

void buildTree(int si, int ss, int se)
{
	if (ss == se)
	{
		if (ar[ss] % 2)	st[si] = {0, 1};
		else 	st[si] = {1, 0};

		return;
	}

	int mid = (ss + se) / 2;
	buildTree(2 * si, ss, mid);
	buildTree(2 * si + 1, mid + 1, se);

	st[si].f = st[2 * si].f + st[2 * si + 1].f;
	st[si].s = st[2 * si].s + st[2 * si + 1].s;
}

int queryEven(int si, int ss, int se, int qs, int qe)
{
	if (qe < ss || qs > se)	return 0;
	if (ss >= qs && se <= qe)	return st[si].f;

	int mid = (ss + se) / 2;
	int l = queryEven(2 * si, ss, mid, qs, qe);
	int r = queryEven(2 * si + 1, mid + 1, se, qs, qe);

	return l + r;
}

int queryOdd(int si, int ss, int se, int qs, int qe)
{
	if (qe < ss || qs > se)	return 0;
	if (ss >= qs && se <= qe)	return st[si].s;

	int mid = (ss + se) / 2;
	int l = queryOdd(2 * si, ss, mid, qs, qe);
	int r = queryOdd(2 * si + 1, mid + 1, se, qs, qe);

	return l + r;
}

void updateST(int si, int ss, int se, int qi, int value)
{
	if (ss == se)
	{
		if (value % 2)	st[si] = {0, 1};
		else 	st[si] = {1, 0};

		ar[ss] = value;
		return;
	}

	int mid = (ss + se) / 2;
	if (qi <= mid)	updateST(2 * si, ss, mid, qi, value);
	else 	updateST(2 * si + 1, mid + 1, se, qi, value);

	st[si].f = st[2 * si].f + st[2 * si + 1].f;
	st[si].s = st[2 * si].s + st[2 * si + 1].s;
}


void solution()
{
	int n;		cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> ar[i];

	buildTree(1, 1, n);
	// for(int i = 1; i <= 4*n; i++)
	// {
	// 	pii value=st[i];
	// 	cout<<value.f<<" "<<value.s<<endl;
	// }

	int q;		cin >> q;
	while (q--)
	{
		int a, b, c; 	cin >> a >> b >> c;

		switch (a)
		{
		case 0:
			if (ar[b] % 2 == c % 2)	break;
			else	updateST(1, 1, n, b, c);
			break;

		case 1:
			cout << queryEven(1, 1, n, b, c) << endl;
			break;

		case 2:
			cout << queryOdd(1, 1, n, b, c) << endl;
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
SAMPLE INPUT
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6

SAMPLE OUTPUT
2
2
4
*/