#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ma 1000001
int main()
{
    ll n,i;ll j;
    ll pr[ma];
    for(i=0;i<ma;i++)
    {
        pr[i]=1;
    }pr[0]=0;pr[1]=0;
    for(i=2;i<ma;i++)
    {
        if(pr[i]==1)
        {for(j=i*i;j<ma;j+=i)
        pr[j]=0;
    }}
    cin>>n;
    float ans=n;
    if(pr[n]==1)
    cout<<n-1<<"\n";
    else
    {
        for(i=2;i<=n/2;i++)
        {if(pr[i]==1&&(n%i==0))
        {float z=float(i);
        double x=double((z-1)/z);
            ans=ans*x;
        }
    }
    cout<<ans<<"\n";
    }
    return 0;
}