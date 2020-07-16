#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)

const int MOD = 1e9+7;
const int SIZE_INT = 16;

int countMaxSetBits(int left, int right) 
{ 
    while ((left | (left + 1)) <= right) 
        left |= left + 1; 
  
    return left; 
} 

void solve()
{
    ll X, Y, L, R;
    cin>>X>>Y>>L>>R;

    ll result;
    if(X==0 || Y==0){
        result = 0;
    }
    else if(L == R){
        result = L;
    }
    else if(L==0 && R==0){
        result = 0;
    }
    else{
        result = X | Y;
        // if(result > R){
        //     while(result>R)
        //         result = result >> 1;
        // }
        // else if(result < L){
        //     while(result < L)
        //         result = result << 1;
        // }
        
        if(result>R || result<L)
            result = countMaxSetBits(L, R);
    }
    
    cout<<result<<"\n";
}

int main()
{
    //two lines to speed-up
    cin.tie(0);
    ios::sync_with_stdio(false);

    // solve();

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        solve();
    }

    return 0;
}