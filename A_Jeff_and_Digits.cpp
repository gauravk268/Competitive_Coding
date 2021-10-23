#include <bits/stdc++.h>
#define int long long int
using namespace std;
 
 int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int i, c0 = 0, c5 = 0;
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
     cin>>a[i];
     
    for (i = 0; i < n; i++) {
        if (a[i] == 0)
            c0++;
        else
            c5++;
    }
 
    // The number of 5s that can be used
    c5 = floor(c5 / 9) * 9;
    if (c0 == 0) // The number can't be
        cout << -1; // made multiple of 10
    else if (c5 == 0) // The only multiple of 90
        cout << 0; // that can be made is 0
    else {
        for (i = 0; i < c5; i++)
            cout << 5;
        for (i = 0; i < c0; i++)
            cout << 0;
    }
return 0;
}
