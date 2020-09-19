#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x)   cout<<#x<<"="<<x<<endl

int maxheight(vector<ll> &v, ll h)
{
    ll n=v.size(), result=0;
    sort(v.begin(), v.end(), greater<ll>());
    if(accumulate(v.begin(), v.end(), 0) < h)   return -1;
    if(h==0)    return v[0];

    for(ll i=1; i<n; i++)
    {
        ll diff=v[i-1]-v[i];
        // cout<<diff*i<<endl;
        
        if(result+(diff*i) == h)
        {
            return v[i];
        }
        else if(result+(diff*i) > h)
        {
            diff=h-result;
            ll temp=diff/i;

            if(temp<1)  return v[i-1]-1;
            else return v[i-1]-temp;
        }
        else result+=(diff*i);
    }

    ll s=v[n-1];
    if(result<h)
    {
        while(result<h)
        {
            result+=n;
            s--;
        }
    }
    return s;
}



int main(){
    ll n,h;
    cin>>n;

    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    cin>>h;
    
    cout<<maxheight(a, h)<<endl;
}

/*
Sample Input
4
15 19 12 13
6
Sample Output
14

https://hack.codingblocks.com/app/contests/1783/1756/problem

#                   1
#                   2  
#                   3
#                   4

# #                 6 
# #                 8
# # #               11 
# # # #             15 
# # # #             19

# # # #             23
# # # #             27
# # # #             31
# # # #             35
# # # #             39

# # # #             43
# # # #             47
# # # #             51
# # # #             55
# # # #             59
*/