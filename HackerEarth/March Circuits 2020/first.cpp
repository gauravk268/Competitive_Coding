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

void solve() {
    int N;  cin>>N;

    bool handShake[N][N];
    MEM(handShake, true);

    int count_handShake = 0;

    F0R(i, N){
        handShake[i][i] = false;
        count_handShake++;
    }

    F0R(i, 10){
        int temp;   cin>>temp;

        F0R(j, 9){
            int notFriend;  cin>>notFriend;
            if(handShake[temp][notFriend] == true){
                handShake[temp][notFriend] = false;
                count_handShake++;
            }
        }
    }

    count_handShake = (N*N-N) - count_handShake;
    cout<<count_handShake<<endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	solve();
	
    // int T; cin >> T;
    // FOR(i, 1, T+1) {
    // }
	
	return 0;
}