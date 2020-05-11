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
    int n;
    cin>>n;

    int x[n];
    vector<int> value;

    int temp=0;
    FoR(i, n)
    {
        cin>>x[i];

        if(i>0 && x[i]-x[i-1]<=2)
        {   
            temp++;
        }
        else
        {
            if(temp)
                value.push_back(temp);
                
            temp=1;
        }
    }
    value.push_back(temp);
    
    sort(value.begin(), value.end());
    int min=0;
    
    
    cout<<value[0]<<" "<<value.back()<<"\n";
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