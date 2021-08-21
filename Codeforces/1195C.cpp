#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<ll> vll;

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define endl "\n"
#define trav(x, a) for (auto &x : a)
#define deb(x) cerr << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE                \
	freopen("input.txt", "r", stdin); \
	// freopen("output.txt", "w", stdout);

const int INF = 1e9 + 7;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7; // used in most problems

int a[2][100005];
int recursive(int k, int p)
{
	if (k < 0)	return 0;

	int result = 0;
	if(p== -1){
			int t1 = max(a[0][k] + recursive(k - 1, 0), recursive(k - 1, -1));
			int t2 = max(a[1][k] + recursive(k - 1, 1), recursive(k - 1, -1));
			result=max(t1, t2);
	}else if(p==0){
		result = max(a[1][k] + recursive(k - 1, 1), recursive(k - 1, -1));
	}else if(p==1){
		result = max(a[0][k] + recursive(k - 1, 1), recursive(k - 1, -1));
	}

	return result;
}

int mem[100005][3];
int memoized(int k, int p){
	if (k < 0)	return 0;

	p++;
	if(mem[k][p]!= -1)	return mem[k][p];

	int result = 0;
	if(p== 0){
			int t1 = max(a[0][k] + memoized(k - 1, 0), memoized(k - 1, -1));
			int t2 = max(a[1][k] + memoized(k - 1, 1), memoized(k - 1, -1));
			result=max(t1, t2);
	}else if(p==1){
		result = max(a[1][k] + memoized(k - 1, 1), memoized(k - 1, -1));
	}else if(p==2){
		result = max(a[0][k] + memoized(k - 1, 1), memoized(k - 1, -1));
	}

	return mem[k][p]=result;
}

void solution()
{
	memset(mem, -1, sizeof(mem));

	int n;
	cin >> n;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	cout<<"recursive: "<<" "<<recursive(n-1, -1)<<endl;
	cout<<"memoized: "<<" "<<memoized(n-1, -1)<<endl;
	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	ONLINE_JUDGE;
	cin >> t;

	while (t--)
	{
		solution();
	}

	showRunTime;
	return 0;
}

/*

3
5
9 3 5 7 3
5 8 1 4 5
3
1 2 9
10 1 1
1
7
4

output
29
19
7

*/