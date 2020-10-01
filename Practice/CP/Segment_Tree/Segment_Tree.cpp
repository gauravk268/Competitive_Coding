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
//minST is the minimum segment tree
//ar is the array containing all the elements
//si=currentIndex, ss=startIndex, se=endIndex

int minST[400004], ar[100001]; 
void buildTree(int si, int ss, int se)
{	
	if(ss==se)	minST[si]=ar[ss];

	int mid=(ss+se)/2;
	buildTree(2*si, ss, mid);
	buildTree(2*si +1, mid+1, se);

	minST[si]=min(minST[2*si], minST[2*si +1]);
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

void updateST(int si, int ss, int se, int qi)
{
	if(ss==se)
	{
		minST[si]=ar[ss];
		return;
	}

	int mid=(ss+se)/2;
	if(qi<=mid)	updateST(2*si, ss, mid, qi);
	else 	updateST(2*si +1, mid+1, se, qi);

	minST[si]=min(minST[2*si], minST[2*si +1]);
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

Output
*/