#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x)   cout<<#x<<"="<<x<<endl

ll woodCollected(vector<ll> &v, int cut)
{
    ll result=0;
    for(int i=v.size()-1; i>=0; i--)
    {
        if(v[i]<=cut)   break;
        result+=(v[i]-cut);
    }

    return result;
}

int solution(vector<ll> &v, int h)
{
    if(accumulate(v.begin(), v.end(), 0)<h) return -1;

    int n=v.size();
    sort(v.begin(), v.end());

    int l=0, r=v[n-1], m;    
    while(l<=r)
    {
        m=l+((r-l)/2);
        int c=woodCollected(v, m);

        if(c==h)    return m;

        if(c>h) l=m+1;
        else    r=m-1;
    }

    return solution(v, h+1);
}

int main(){

    ll n,h;
    cin>>n;

    vector<ll> a(n);
    for(ll i=0;i<n;i++)     cin>>a[i];
    cin>>h;

    cout<<solution(a, h)<<endl;

    return 0;
}

/*
Sample Input
4
15 19 12 13
6
Sample Output
14

https://hack.codingblocks.com/app/contests/1783/1756/problem


*/