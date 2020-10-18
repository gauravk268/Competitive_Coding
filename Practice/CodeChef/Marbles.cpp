#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x)   cout<<#x<<"="<<x<<endl
#define showRunTime  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);    freopen("output.txt", "w", stdout);

#define f  first
#define s  second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

ll combi(ll n, ll r)
{
	if(r > n/2)
		r = n-r;

	ll result=1;
	for(int i=0; i<r; i++)
	{
		result*=n;
		result/=(i+1);
		n--;
	}

	return result;
}

void solution()
{
    ll k, n;	cin>>n>>k;

    cout<<combi(n-1, n-k)<<endl;
    return;
}

int main()
{
	// ONLINE_JUDGE;

    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

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
Input:
2
10 10
30 7

Output:
1
475020
*/