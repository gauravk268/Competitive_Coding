    

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define MEM(a, b) memset(a, b, sizeof(a))
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int gcd(int a, int b) { 
   if (b == 0) 
      return a; 
   return gcd(b, a % b);  
}

void solve() {
    int x, y, p, q;
    cin>>x>>y>>p>>q;
    
    int b1=1, b2=1, b3=1;
    
    b1 = p * y;
    b2 = x * q;
    b3 = x * y;
    
    int commonFactor = gcd(b1, gcd(b2, b3));
    while(commonFactor != 1){
        b1 /= commonFactor;
        b2 /= commonFactor;
        b3 /= commonFactor;
        commonFactor = gcd(b1, gcd(b2, b3));
    }
    
    cout<<b1<<" "<<b2<<" "<<b3<<endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	solve();
    // int T; cin >> T;
    // FOR(i, 1, T+1) {
    // }
	
	return 0;
}