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
    ll n, m;
    int flag=1;
    cin>>n>>m;

    vector<int> a(n);
    vector<int> b(n);
    FoR(i, n){
        cin>>a[i];
        b[i] = a[i];
    }
    
    sort(b.begin(), b.end());
    
    vector<vector <int>> robot(n+1);
    // if(a == b)
    // {
    //     cout<<0<<"\n";
    //     flag = 0;
    // }
    // else
    // {
        FoR(i, m){
            int temp1, temp2;
            cin>>temp1>>temp2;

            robot[temp1].push_back(temp2);
            robot[temp2].push_back(temp1);
        }
    // }
    
    if(flag){
        ll count=0;
        FoR(i, n){
            if(a[i] != b[i]){
                auto it = find(a.begin(), a.end(), b[i]);
                int dis = distance(a.begin(), it);

                int temp = a[i];
                a[i] = a[dis];
                a[dis] = temp;

                if( find(robot[i+1].begin(), robot[i+1].end(), dis+1) == robot[i+1].end()
                    && find(robot[dis+1].begin(), robot[dis+1].end(), i+1) == robot[dis+1].end() ){
                    count++;
                }
            }
        }
        cout<<count<<"\n";
    }
    
    // FoR(i, n){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    
    a.clear();
    b.clear();
    FoR(i, n+1){
        robot[i].clear();
    }

    robot.clear();
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