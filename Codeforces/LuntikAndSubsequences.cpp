#include<bits/stdc++.h>
using namespace std;
#define int long long
int main(){
    int t;cin>>t;
    while (t--)
    {
        int n,c0=0,c1=0,ans=0;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin>>arr[i];
            if(arr[i]==0)c0++;
            if(arr[i]==1)c1++;
        }
        cout<<c1*pow(2,c0)<<'\n';   
    }    
    return 0;
}