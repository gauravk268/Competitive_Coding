#include<bits/stdc++.h>
using namespace std;
#define N 800000000000
#define int long long
signed main() {
    set<int> s;
    for(int i = 1; i * i <= N; i += 2) {
        int x = i * i - 1;
        if(x % 8 == 0) {
            s.insert(x / 8);
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int mat[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int mvs = 0;
            for(int j = 0; j < n; j++) {
                auto it = s.lower_bound(mat[i][j]);
                int d1 = abs(*it - mat[i][j]);
                it--;
                int d2 = abs(*it - mat[i][j]);

                mvs += min(d1, d2);
            }
            ans = min(ans, mvs);
        }
        for(int i = 0; i < n; i++) {
            int mvs = 0;
            for(int j = 0; j < n; j++) {
                auto it = s.lower_bound(mat[j][i]);
                int d1 = abs(*it - mat[j][i]);
                it--;
                int d2 = abs(*it - mat[j][i]);

                mvs += min(d1, d2);
            }
            ans = min(ans, mvs);
        }
        cout << ans << endl;
    }
}