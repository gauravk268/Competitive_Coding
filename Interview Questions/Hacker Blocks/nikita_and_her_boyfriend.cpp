//?https://hack.codingblocks.com/app/contests/1783/1759/problem
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int a, b;
    cin >> a >> b;
    if(a > b) {
        cout << abs(a - b) << endl;
        return 0;
    }
    if(a % 2 != 0 and b % 2 == 0) {
        cout << abs(a - b) << endl;
        return 0;
    }
    if(a % 2 == 0 and b % 2 != 0) {
        cout << abs(a - b) << endl;
        return 0;
    }

    if(a == b) {
        if(a == 0) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
            cout << a << endl;
        }
    } else {
        int x = (b - a) / 2;
        if((a & x) == 0) {
            cout << 2 << endl;
            cout << x << " " << a + x << endl;
        } else {
            cout << 3 << endl;
            int arr[3] = {a, x , x};
            sort(arr, arr + 3);
            cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        }
    }
}