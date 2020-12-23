#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define INF 	 1e9+7
#define deb(x) 	 cout<<#x<<"="<<x<<endl
#define showRunTime  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

#define f  first
#define s  second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

// #define ENABLE_DEBUG

int minST[400004], ar[100001]; 
void buildTree(int si, int ss, int se)
{	
	if(ss==se)
	{
		minST[si]=ar[ss];
		return;
	}

	int mid=(ss+se)/2;
	buildTree(2*si, ss, mid);
	buildTree((2*si) +1, mid+1, se);

	minST[si]=min(minST[2*si], minST[(2*si) +1]);
}

int query(int si, int ss, int se, int qs, int qe)
{
	if(qe<ss || qs>se)	return INF;
	if(ss>=qs && se<=qe)	return minST[si];

	int mid=(ss+se)/2;
	int l=query(2*si, ss, mid, qs, qe);
	int r=query(2*si+1, mid+1, se, qs, qe);

	return min(l, r);
}


void solution()
{
	int n;		cin>>n;

	for(int i=1; i<=n; i++)
		cin>>ar[i];

	buildTree(1, 1, n);

	int q;		cin>>q;
	while(q--)
	{
		int a, b;	cin>>a>>b;

		cout<<query(1, 1, n, a+1, b+1)<<endl;
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
Input:
3
1 4 1
2
1 1
1 2
Output:
4
1
*/