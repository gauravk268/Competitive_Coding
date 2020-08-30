//Rain Water Trapping

#include <bits/stdc++.h>
using namespace std;


void solve()
{
    vector<int> building={3, 0, 0, 2, 0, 4};
    int n=building.size();
    vector<int> maxRight(n), maxLeft(n);
    
    for(int i=0; i<n; i++)
    {
        if(i==0)    maxLeft[i]=building[i];
        maxLeft[i]=max(building[i], maxLeft[i-1]);
    }
    
    for(int i=n-1; i>=0; i--)
    {
        if(i==n-1)    maxRight[i]=building[i];
        maxRight[i]=max(building[i], maxRight[i+1]);
    }
    
    vector<int> amountWater(n);
    for(int i=0; i<n; i++)
        amountWater[i]=min(maxRight[i], maxLeft[i])-building[i];
        
    vector<int> result;
    int temp=0;
    for(int i=0; i<n; i++)
    {
        if(amountWater[i]==0)
        {
            result.push_back(temp);
            temp=0;
        }
        
        temp+=amountWater[i];
    }
    
    if(temp)    result.push_back(temp);
    
    sort(result.begin(), result.end(), greater<int>());
    cout<<result[0]<<endl;
}

int main()
{
    solve();
    return 0;
}
