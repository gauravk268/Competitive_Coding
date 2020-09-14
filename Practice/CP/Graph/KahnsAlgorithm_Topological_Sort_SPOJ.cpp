#include<bits/stdc++.h>
using namespace std;

std::vector<int> ar[10001], result;
int in[10001];


bool Kahns(int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=1; i<=n; i++)
        if(in[i]==0)    pq.push(i);

    while(!pq.empty())
    {
        int curr=pq.top();
        result.push_back(curr);
        pq.pop();

        for(int child:ar[curr])
        {
            in[child]--;
            if(in[child]==0)
                pq.push(child);
        }
    }

    return result.size()==n;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b;

    cin>>n>>m;

    for(int i=1; i<=m; i++) 
        cin>>a>>b, ar[a].push_back(b), in[b]++;

    if(!Kahns(n))
        cout<<"Sandro fails.";
    else
    {
        for(int node:result)
            cout<<node<<" ";
    }

    return 0;
}

/*
Input:
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6

Output:
1 4 3 5 7 8 2 6 

Input:
2 2
1 2
2 1

Output:
Sandro fails.

*/