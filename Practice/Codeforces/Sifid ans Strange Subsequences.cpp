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
#define trav(x,a) for (auto& x: a)
#define deb(x) cerr << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE                \
freopen("input.txt", "r", stdin); \
// freopen("output.txt", "w", stdout);

const int INF = 1e9+7;
const int N   = 1e5+5;
const int MOD = 1e9+7;      // used in most problems

void solution(){
	int n;	cin>>n;
	vector<int> values(n);
	for(int i=0; i<n; i++)	cin>>values[i];

	sort(values.begin(), values.end());
	int result=1;
	int minDiff=INT_MAX;

	for(int i=1; i<n; i++){
		minDiff=min(minDiff, values[i]-values[i-1]);
		if(values[i]-values[i-1] >= values[i] && values[i] <= minDiff){
			result++;
		}
	}

	cout<<result<<endl;
}

int main(){
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
