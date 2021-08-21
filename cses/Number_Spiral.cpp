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
#define fr(i,n)	  for(i=0;i<n;i++)
#define fr1(i,n)	for(i=1;i<=n;i++)

ll rotValue(ll x, ll y){
  // if(x==y)  return pow(2, x)-1;

  ll res = max(x, y)*max(x, y)-max(x, y)+1;
  if(max(x, y)&1){
    if(x>y) return res-(x-y);
    else  return res+abs(x-y);
  }
  else{
    if(x>y) return res+(x-y);
    else  return res-abs(x-y);
  }
}

void solution(){
  ll x, y; cin>>x>>y;
  cout<<rotValue(x, y)<<endl;
}

int main(){
  // ONLINE_JUDGE;

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

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
3
2 3
1 1
4 2
1000000000 1000000000

Output:
8
1
15
999999999000000001

*/