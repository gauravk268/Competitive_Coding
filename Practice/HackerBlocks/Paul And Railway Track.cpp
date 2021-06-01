#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int a[n], b[m];
    for(int i=0; i<n; i++)  cin>>a[i];
    for(int i=0; i<m; i++)  cin>>b[i];

    int dp[n+1][m+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0)    dp[i][j]=0;
            else if(a[i-1] == b[j-1])   dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout<<dp[n][m]<<"\n";
    return 0;
}