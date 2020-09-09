//Maximum Area Histogram

#include <bits/stdc++.h>
using namespace std;

vector<int> NSR(vector<int> &values)
{
    int n=values.size();
    vector<int> result;
    stack<pair<int, int>> s;
    
    for(int i=n-1; i>=0; i--)
    {
        if(s.empty())
            result.push_back(n);
        else if(s.top().first<values[i])
            result.push_back(s.top().second);
        else
        {
            while(!s.empty() && s.top().first>=values[i])
                s.pop();
            
            if(s.empty())   result.push_back(n);
            else    result.push_back(s.top().second);
        }
        
        s.push( make_pair(values[i], i) );
    }
    
    reverse(result.begin(), result.end());
    return result;
}

vector<int> NSL(vector<int> &values)
{
    int n=values.size();
    vector<int> result;
    stack<pair<int, int>> s;
    
    for(int i=0; i<n; i++)
    {
        if(s.empty())
            result.push_back(-1);
        else if(s.top().first<values[i])
            result.push_back(s.top().second);
        else
        {
            while(!s.empty() && s.top().first>=values[i])
                s.pop();
            
            if(s.empty())   result.push_back(-1);
            else    result.push_back(s.top().second);
        }
        
        s.push( make_pair(values[i], i) );
    }
    
    return result;
}

void solve()
{
    vector<int> stocks={6, 2, 5, 4, 5, 1, 6}, left, right;
    left=NSL(stocks);
    right=NSR(stocks);
    int max=0;
    
    // for(auto temp:right)
    //     cout<<temp<<" ";
    // cout<<endl;
    
    for(int i=0; i<stocks.size(); i++)
    {
        int area=(right[i]-left[i]-1)*stocks[i];
        
        if(area>max)    max=area;
    }
    
    cout<<max<<endl;
}

int main()
{
    solve();
    return 0;
}
