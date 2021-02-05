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
#define fr(i,n)	  for(int i=0;i<n;i++)
#define fr1(i,n)	for(ll i=1;i<=n;i++)

char strToChar(string s){
  char result='a';
  int temp=0;
  for(int i=0; i<4; i++){
    if(s[i] == '1'){
      temp += pow(2, 3-i);
    }
  }
  result += temp;
  return result;
}

void solution()
{
  ll n; cin>>n;
  string s;   cin>>s;

  for(int i=0; i<n; i+=4){
    string temp;
    temp = s.substr(i, 4);

    cout<<strToChar(temp);
  }
  cout<<endl;
}

int main()
{
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

Sample Input:
3
4
0000
8
00001111
4
1001
Sample Output:
a
ap
j

*/