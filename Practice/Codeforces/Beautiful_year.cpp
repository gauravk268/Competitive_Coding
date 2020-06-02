// https://codeforces.com/problemset/problem/271/A

#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)
#define pb push_back
#define endl "\n"

const int MOD = 1e9+7;
const int SIZE_INT = 16;

bool isdiff(int a, int b, int c, int d){
    if((a!=b) && (a!=c) && (a!=d) && (b!=c) && (b!=d) && (c!=d))    
        return true;
    else    
        return false;
}

bool isSame(int a, int b, int c, int d){
    if((a==b) || (a==c) || (a==d) || (b==c) || (b==d) || (c==d))    
        return true;
    else    
        return false;
}


void solve()
{
    int n;
    cin>>n;

    int a, b, c, d;

    // while(n>0){
    //     n++;

    //     a = n/1000;
    //     b = (n%1000)/100;
    //     c = ((n%1000)%100)/10;
    //     d = ((n%1000)%100)%10;

    //     if(isdiff(a, b, c, d))
    //         break;
    // }

    bool flag=true;
    a=0, b=0;
    while(flag){
        int temp= ++n;

        a = temp/1000;
        b = (temp%1000)/100;
        c = ((temp%1000)%100)/10;
        d = ((temp%1000)%100)%10;

        flag = isSame(a, b, c, d);
    }



    cout<<n<<endl;
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