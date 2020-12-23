#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)

const int MOD = 1e9+7;
const int SIZE_INT = 16;

void solve()
{
    int N, K;
    cin>>N>>K;

    vector<int>a(N);
    vector<int>b(N);
    
    FoR(i, N){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());
    bool flag=true;
    
    for(int i=1; i<=K; i++){
        vector<int>p;
        vector<int>q;       
        for(int j=i-1; j<N; j+=K){
            p.push_back(a[j]);
            q.push_back(b[j]);
        }
        sort(p.begin(), p.end());
    
        if( p != q)
        {
             flag = false;
             break;
        }
        
        p.clear();
        q.clear();
    }

    if(flag)
        cout<<"yes\n";
    else
        cout<<"no\n";
       
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