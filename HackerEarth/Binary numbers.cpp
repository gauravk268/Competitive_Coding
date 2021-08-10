#include<bits/stdc++.h>
using namespace std;

int dp[40];

void solve(){
  int k;  cin>>k;

  string ans="";
  int t=0;
  
  for(int i=39; i>=0; i--){
    if(dp[i] <= k)
    {
      ans += "1";
      k -= dp[i];
      t=1;
    }
    else if(t==1)
    {
      ans += "0";
    }
  }

  cout<<ans<<endl;
}

int main(){
  dp[0]=1;
  dp[1]=2;

  for(int i=2; i<40; i++)
  {
    dp[i] = dp[i-1]+dp[i-2];
  }

  int t;  cin>>t;

  while(t--){
    solve();
  }
}