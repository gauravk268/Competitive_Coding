#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x)   cout<<#x<<"="<<x<<endl

#define f  first
#define s  second
#define pb push_back
#define mp make_pair

// #define ENABLE_DEBUG


void solution()
{
	int n;
	cin >> n;

	vector<ll> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];

	sort(v.begin(), v.end());

	std::vector<ll> result(n);
	int count = 0;

	// int i=0, j=n-1;
	for(int i=0; i<n/2 +1; i++)	result[i*2]=v[n-1-i];
	for(int i=0; i<n/2; i++){
		result[i*2 +1]=v[i];
		if(i*2 + 1 !=0 && i*2+1!=n-1)	count++;
	}

	cout << count << endl;
	for (int i = 0; i < n; i++)	cout << result[i] << " ";
	cout << endl;
}

int main()
{
#ifdef ENABLE_DEBUG
	freopen("input.txt" , "r", stdin );
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin>>t;

	while (t--)
	{
		solution();
	}

	return 0;
}

/*
inputCopy
5
1 2 3 4 5
outputCopy
2
3 1 4 2 5
*/