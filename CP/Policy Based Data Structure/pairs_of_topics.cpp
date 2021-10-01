//?https://codeforces.com/problemset/problem/1324/D
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> PBDS;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
    }

    PBDS St;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans += St.size() - St.order_of_key({-c[i], 10000000});
        St.insert({c[i], i});
    }
    cout << ans << endl;


}

