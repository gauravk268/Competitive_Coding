#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define f first
#define s second

void primMST(vector<pi> v[],int n,int e)
{ priority_queue< pi, vector <pi> , greater<pi> > pq; 
  
    int src = 1; // Taking vertex 0 as source 
  
    // Create a vector for keys and initialize all 
    // keys as infinite (INF) 
    int key[n+1],parent[n+1];
    bool inMST[n+1];
    for(int i=0;i<=n;i++)
    {key[i]=INT_MAX;
    parent[i]=-1;
    inMST[i]=false;}
  
    // Insert source itself in priority queue and initialize 
    // its key as 0. 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
  
    /* Looping till priority queue becomes empty */
    while (!pq.empty()) 
    { 
        // The first vertex in pair is the minimum key 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted key (key must be first item 
        // in pair) 
        int u = pq.top().second; 
        pq.pop(); 
  
        inMST[u] = true; // Include vertex in MST 
  
        // Traverse all adjacent of u 
        for (int x=0;x<v[u].size();x++)
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int k = v[u][x].f; 
            int weight = v[u][x].s; 
  
            // If v is not in MST and weight of (u,v) is smaller 
            // than current key of v 
            if (inMST[k] == false && key[k] > weight) 
            { 
                // Updating key of v 
                key[k] = weight; 
                pq.push(make_pair(key[k], k)); 
                parent[k] = u; 
            } 
        } 
    } 
  
    // Print edges of MST using parent array 
    for (int i = 2; i <= n; ++i) 
        printf("%d - %d\n", parent[i], i);


    
}

int main() {
    int n,e;
    cin>>n>>e;
    vector<pi> v[n+1];
    int i;
    for(i=0;i<e;i++)
    {int w,x,y;
    cin>>x>>y>>w;
    v[x].push_back(make_pair(y,w));
    v[y].push_back(make_pair(x,w));
    }
primMST(v,n,e);
	return 0;
}
