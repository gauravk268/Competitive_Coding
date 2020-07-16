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
    int n, q;
    cin>>n>>q;

    string patient;
    cin>>patient;

    int value[27];
    MEM(value, 0, 27);

    int max=0;
    FoR(i, n){
        int temp;
        temp = patient[i]-97;
        //a will have value 0

        value[temp]++;
        
        if(value[temp] > max)
            max = value[temp];
    }

    int count[max];
    MEM(count, 0, max);
    
    FoR(i, 27){
        if(value[i] == 0)
            continue;
           
        count[value[i]-1]++;
    }
    
    FoR(i, q){
        int temp=0, sum=0;
        cin>>temp;
        
        for(int j=temp; j<max; j++){
            sum += (count[j] * (j-temp+1));
        }
        
        cout<<sum<<"\n";
    }
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