#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     
     int n,x;
     cin>>n;
     int a[n];
    int max=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        
        if(a[i]>max)
       { max=a[i];
        x=i; }
    }
    int ans=-1;
    for(int i=0;i<n;i++)
   {
      if(max==a[i]&&((a[i]>a[i-1] && i-1>=0)||(a[i]>a[i+1] && i+1<n)))
  {
   ans=i+1;
   break;
    
    }
}
    cout<<ans<<endl;
    }
    return 0;
}
