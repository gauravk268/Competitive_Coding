// https://codeforces.com/problemset/problem/110/A

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
    string number;
    cin>>number;

    bool flag=true;
    
    int length = 0;
    FoR(i, number.length()){
        if(number[i]=='4' || number[i] == '7')
            length++;
    }
    // cout<<length<<"\n";

    if(length == 0)
        flag = false;

    while(length!=0){
        int rem = length%10;

        if(rem!=4 && rem!=7){
            flag = false;
            break;
        }

        length /= 10;
    }

    if(flag){
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
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