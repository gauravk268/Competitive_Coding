// https://projecteuler.net/problem=4

#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)
#define pb push_back
#define endl "\n"

const int MOD = 4000000;
const int SIZE_INT = 16;

bool isPalindrome(ll num){
    ll reverse=0, temp = num;

    while(temp>0){
        reverse *= 10;
        reverse += temp%10;
        temp /=10;
    }
    // cout<<reverse<<endl;

    if(num == reverse)
        return true;
    return false;
}

void solve()
{
    ll result, max=0;
    // result = 10000001;
    // if(isPalindrome(result))
    //     cout<<"test"<<endl;

    for(int i=999; i>=101; i--){
        for(int j=i-1; j>=100; j--){
            result = i * j;
            if(isPalindrome(result)){
                if(max < result)
                    max = result;
                break;
            }
        }
    }

    cout<<max<<endl;
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

    // return 0;
}