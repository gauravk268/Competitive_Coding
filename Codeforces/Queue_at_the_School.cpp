// https://codeforces.com/problemset/problem/266/B

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

void solve()
{
    int n, t;
    cin>>n>>t;

    string students;
    cin>>students;


    while(t--){
        for(int i=0; i<n-1; i++){
            if(students[i] == 'B' && students[i+1]=='G'){
                students[i] = 'G';
                students[i+1] = 'B';
                i++;
            }
        }
        // cout<<t<<"\n";
    }


    // vector<int> boys;

    // FoR(i, n){
    //     if(students[i] == 'B'){
    //         boys.pb(i);
    //     }
    // }

    // int a=n-1;
    // for(int i=boys.size()-1; i>=0; i--){
    //     // cout<<"po\n";
    //     if(boys[i] == a)
    //         continue;

    //     if(a-boys[i] <= t){
    //         int temp = boys[i]; 
    //         students[ boys[i] ] = 'G';
    //         boys[i] = a;
    //         students[ boys[i]] = 'B';
    //         a = temp;
    //     }
    //     else{
    //         int temp = boys[i]; 
    //         students[ boys[i] ] = 'G';
    //         students[ temp+t ] = 'B';
    //         a = temp;
    //     }
    // }

    cout<<students<<"\n";
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