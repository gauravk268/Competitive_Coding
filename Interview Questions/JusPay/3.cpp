#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> vis(n, false);
    int res = -1;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        if (!vis[i]) {
            vis[i] = true;
            // temp+=i;
            int j = a[i];
            bool enter = false;
            stack<int> s;
            s.push(i);
            // cout<<i<<" ";
            while (j != -1 && !vis[j]) {
                // temp+=j;
                s.push(j);
                // cout<<j<<" ";
                vis[j] = true;
                j = a[j];
                enter = true;
            }
            if (j != -1 && vis[j] && enter) {
                temp = 0;
                while (!s.empty() and s.top() != j) {
                    temp += s.top();
                    s.pop();
                }
                if (s.empty()) {
                    continue;
                }
                if (s.top() == j) {
                    temp += s.top();
                }

                res = max(res, temp);
            }
        }
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}