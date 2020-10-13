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

const int MAXN = (1<<20);

vector<ll> value;
void solution()
{
	value.clear();
	ll temp, n, x, p, k;		cin >> n >> x >> p >> k;
	p--, k--;

	bool flag = false;
	for (int i = 0; i < n; i++)		
	{
		cin >> temp;
		value.pb(temp);

		if(temp == x)
			flag = true;
	}

	sort(value.begin(), value.end());

	ll ans=0;
	if(flag)
	{
		if(value[p]==x)
		{
			cout<<ans<<endl;
			return;
		}
	}
	else
	{
		value[k]=x;
		ans++;
	}

	sort(value.begin(), value.end());
	auto index = find(value.begin(), value.end(), x);
	
	if(value[p] == x)
	{
		cout<<ans<<endl;
		return;
	}
	else
	{
		int dist = abs(k - (index-value.begin()));
		while(dist--)
		{
			value[k] = x;
			ans++;
			sort(value.begin(), value.end());

			if(value[p] == x)
			{
				cout<<ans<<endl;
				return;
			}
		}
	}
	

	cout<<-1<<endl;
}

int main()
{
// 	freopen("input.txt", "r", stdin);	freopen("output.txt", "w", stdout);

	std::ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int t = 1;
	cin >> t;

	while (t--)
	{
		solution();
	}

	showRunTime;
	return 0;
}

/*
Input
2
5 4 3 4
4 9 7 0 8
2 25 1 2
100 20

Output
1
-1
*/