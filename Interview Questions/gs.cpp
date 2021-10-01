#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> v, int n, int k) {
    int M = v[k] + n; // Assuming that Kth racer is the winner
    int curr = 1;

    for(int i = n - 1; i >= 0; i--) {
        if(i == k)
            continue;
        int temp = v[i] + curr;
        if(temp > M) // Assumption is failed
            return false;
        curr++;
    }
    return true;
}

int canWin(vector<int> v, int n) {
    sort(v.begin(), v.end());
    int pos = n; // Initially assuming that last racer is the winner
    int l = 0, h = n - 1;
    // AIM : To find the pos of the racer which can be winner with lowest score.

    while(l <= h) {
        int m = l + (h - l) / 2;
        if(check(v, n, m)) {
            pos = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    return n - pos;
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    cout << canWin(v, n) << endl;
}