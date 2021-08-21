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
#define fr1(i,n)	for(int i=1;i<=n;i++)

void numChar(int n, int max){
  int f=1;
  while(max){
    if(n&f)   cout<<"1";
    else      cout<<"0";
    max>>=1;
    f<<=1;
  }
}

vector<int> gray(int n){
  if(n==1) return {0, 1};

  vector<int> start, last;
  start = gray(n-1);
  last=start;

  fr(i, last.size()){
    last[i] += (1<<(n-1));
  }

  reverse(last.begin(), last.end());
  start.insert(start.end(), last.begin(), last.end());
  return start;
}

void solution(){
  int n;  cin>>n;
  vector<int> result = gray(n);
  int maxValue = *max_element(result.begin(), result.end());

  for(int i=0; i<result.size(); i++){
    numChar(result[i], maxValue);
    cout<<endl;
  }
}

int main(){
  // ONLINE_JUDGE;

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*



*/