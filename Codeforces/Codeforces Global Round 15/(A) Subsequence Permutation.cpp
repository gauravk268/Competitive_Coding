#include <iostream>
#include <string>
#include <algorithm>
// ok
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    string s_ord = s;
    sort(s_ord.begin(), s_ord.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (s[i] != s_ord[i]);

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
        solve();

    return 0;
}
