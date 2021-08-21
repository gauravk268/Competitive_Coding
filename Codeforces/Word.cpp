// https://codeforces.com/problemset/problem/59/A

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
    string input;
    cin>>input;

    int lower=0,upper=0; 
    int n=input.length();
    FoR(i, input.length()){
        if(input[i]>=65  && input[i]<=90 ){
            upper++;

        }
        if(input[i]>=97  && input[i]<=122 ){
            lower++;
        }
    }

    if(upper > lower){
        FoR(i, n){
            if(input[i]>=97  && input[i]<=122)
                input[i] -= 32;

            cout<<input[i];
        }
    }
    else{
        FoR(i, n){
            if(input[i]>=65  && input[i]<=90)
                input[i] += 32;

            cout<<input[i];
        }
    }
    cout<<'\n';

    

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