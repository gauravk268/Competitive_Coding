#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
// typedef long double ld;

// #define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
// #define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
// #define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define MEM(a, b) memset(a, b, sizeof(a))

//const int MX = 100001; //check the limits, dummy

struct shake{
    ll first, second;
};

struct shake value[91];
int num=0;

bool checkIf(ll x, ll y){
    F0R(i, num){
        if((value[i].first == x && value[i].second == y) ||
        (value[i].first == y && value[i].second == x))
            return true;
    }
    return false;
}

void solve() {
    ll N;
    cin>>N;
    
    ll first, second;
    F0R(i, 10){
        cin>>first;
        F0R(j, 9){
            cin>>second;
            if(checkIf(first, second))
                continue;
            value[num].first = first;
            value[num++].second = second;
        }
    }
    
    ll count = (N*(N-1)/2)-num;
    
    cout<<count<<endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    // int T; cin >> T;
    // while(T--) {
    //     solve();
    // }
	solve();
	return 0;
}