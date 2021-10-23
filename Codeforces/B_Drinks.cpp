#include <bits/stdc++.h>
using namespace std;
 
 int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    double a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    double sum=0;
    for(int i=0;i<n;i++)
    sum+=a[i];

    cout<<fixed<<setprecision(12)<<(sum/n);
return 0;
}