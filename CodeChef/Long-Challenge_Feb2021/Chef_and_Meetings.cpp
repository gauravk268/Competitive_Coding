#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define bk back()
#define pb push_back
#define endl "\n"
#define dotl " "

#define fr1(i,a,b) for(int i = (a); i <= (b); ++i)
#define fr(i,a) fr1(i,0,a)
#define rf1(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define rf(i,a) rf1(i,0,a)
#define trav(x,a) for (auto& x: a)

#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

const int MX  = 2e5+5;
const int N   = 1e5+5;
const int MOD = 1e9+7;      // used in most problems
const ld  PI  = acos(-1);   // inverse cos of -1

int fun(string time, string a){
	int i = 0, temp=0;
	vi value;
	while(i < time.length()){
		if(time[i]==':'){
			i++;
			value.push_back(temp);
			temp = 0;
		}
		else{
			temp *= 10;
			temp += (time[i] - '0');
			i++;
		}
	}

  if(a == "PM" && value[0]!=12){
    value[0] += 12;
  }
  else if(a == "AM" && value[0]==12){
    value[0] = 0;
  }

	value.push_back(temp);
  int result = value[0]*100 + value[1];
  return result;
}

void solution(){
  int n;
  string chefTime, c;
  cin >> chefTime>>c;
  int chef = fun(chefTime, c);

  cin >> n;
  int in, out;

  int result = 0;
  string a, b, d, e;
  for (int i = 0; i < n; i++){
    cin >> a>> b>>d>>e;
    in = fun(a, b);
    out = fun(d, e);

    // cout << in << " " << out << endl;

    if(chef >= in && chef <= out)
      cout << "1";
    else
      cout << "0";
  }

  cout << endl;
}

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // ONLINE_JUDGE;
  cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*

2
12:01 AM
4
12:00 AM 11:42 PM
12:01 AM 11:59 AM
12:30 AM 12:00 PM
11:59 AM 11:59 PM
04:12 PM
5
12:00 AM 11:59 PM
01:00 PM 04:12 PM
04:12 PM 04:12 PM
04:12 AM 04:12 AM
12:00 PM 11:59 PM

1100
11101

*/