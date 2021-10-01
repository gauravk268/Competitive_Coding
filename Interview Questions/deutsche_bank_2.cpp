#include<bits/stdc++.h>
using namespace std;
int total;
vector<int> rows, cols;

int solve(int i, int j, int n) {
    if(rows[i - 1] > 0) {
        total -= rows[i - 1];
        rows[i - 1] = 0;
        for(int k = 0; k < n; k++) {
            if(cols[k] > 0) {
                cols[k]--;
            }
        }
    }

    if(cols[j - 1] > 0) {
        cols[j - 1] = 0;
        for(int k = 0; k < n; k++) {
            if(rows[k] > 0) {
                rows[k]--;
                total--;
            }
        }
    }
    return total;
}

signed main() {
    int n;
    cin >> n;
    total = n * n;
    rows.assign(n, n);
    cols.assign(n, n);

    int k;
    cin >> k;
    while(k--) {
        int i, j;
        cin >> i >> j;
        cout << solve(i, j, n) << endl;
    }
}