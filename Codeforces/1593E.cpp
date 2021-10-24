#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define ll long long
using namespace std;
 
void solve(){
    ll n,k; cin >> n >> k;
    vector<vector<int>> g(n);
    vector<int> edge_count(n,0),dist(n,-1);
    for(ll i=0;i<n-1;i++) {
        ll u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v); edge_count[u]++;
        g[v].push_back(u); edge_count[v]++;
    }
    queue<ll> bfs;
    for(ll i=0;i<n;i++) if(edge_count[i]==1) {bfs.push(i); dist[i]=0;}
    while (bfs.size()) {
        int u = bfs.front(); bfs.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                edge_count[v]--;
                if(edge_count[v]==1){
                    dist[v] = dist[u] + 1;
                    bfs.push(v);
                }
            }
        }
    }
    ll ct=0;
    for(ll i=0; i < n; i++)
    {if(dist[i]>=k) ct++;}
    cout<< ct <<"\n";
}
 
int main()
{
    ll t=1; cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
