#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)
#define pb push_back

const int MOD = 1e9+7;
const int SIZE_INT = 16;

void solve()
{
    ll x, n;
    cin>>x>>n;
    int arr[5];
    arr[0]=0;
    arr[1]=1;

    FOR(i, 2, 5){
        arr[i] = i * arr[i-1];
    }

    // FoR(i, 10){
    //     cout<<arr[i]<<" ";
    // }


    ll result;
    if(n<5){
        x%=10;
        int value = arr[n]%10;
        result = (pow(x, value));
        result = result%10;
    }
    else{
        result = pow(x, 0);
    }
    
    cout<<result<<"\n";
}

int main()
{
    //two lines to speed-up
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();

    // int testCases;
    // cin >> testCases;

    // while (testCases--)
    // {
    //     solve();
    // }

    return 0;
}