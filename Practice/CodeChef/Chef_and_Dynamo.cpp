#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define dotl " "
#define MOD 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

ull biExpo(ull base, ull power){
  ull ans=1;
  while(power!=0){
    if(power%2){
      power--;
      ans*=base;
    }
    else{
      power = power/2;
      base *= base;
    }
  }

  return ans;
}

// int solution(){
//   cout<<biExpo(10, 2)<<endl;
//   return 1;
// }

int solution()
{
  ull n;  cin>>n;
  ull a, b, c, d, e, s;
  ull powValue = biExpo(10, n);

  cin>>a;
  s = a + 2*powValue;  cout<<s<<endl<<flush;
  cin>>b;
  c = powValue-b;   cout<<c<<endl<<flush;
  cin>>d;
  e = powValue-d;   cout<<e<<endl<<flush;

  int result;   cin>>result;
  if(result == -1)  return 0;
  return 1;
}

int main()
{
	// ONLINE_JUDGE;

	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1, value=1;
	cin >> t;

	while (t-- && value){
		value = solution();
	}

	showRunTime;
	return 0;
}

/*

You             Grader
                1
                2
                10
50
                10
12
                10
8
                1

*/