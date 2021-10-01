#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &a, int key, int k) {

    // Checking that 'key' can become as the maximum number of student in a group
    priority_queue<int> pq; // max heap

    for(auto x : a) {
        pq.push(x);
    }

    while(k--) {
        int x = pq.top();

        if(x <= key and k == 0)
            return true;
        else if(x <= key){
            return false; // Some mics are left out
        }
        pq.pop();
        pq.push(x - key);
        pq.push(key);
    }

    if(pq.top() <= key)
        return true;
    return false;
}

signed main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int mx = 0;
    for(auto &x : a) {
        cin >> x;
        mx = max(mx, x);
    }

    int low = 1;
    int high = mx;
    int ans = mx;
    // Aim : is to minimize the maximum number of students in grp sharing one mic

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(isValid(a, mid, k - n)) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}