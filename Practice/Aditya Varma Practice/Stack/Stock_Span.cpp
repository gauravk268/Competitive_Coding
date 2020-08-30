//Stock Span problem or in simple words, consecutive smallest
// elements to left problem

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> stocks={100, 80, 60, 70, 60, 75, 85}, result;
    stack<pair<int, int>> s;
    
    for(int i=0; i<stocks.size(); i++)
    {
        if(s.empty() || s.top().first >stocks[i])
            result.push_back(1);
        else if(s.top().first <=stocks[i])
        {
            while(!s.empty() && s.top().first <=stocks[i])
                s.pop();
                
            if(s.empty())   result.push_back(i);
            else    result.push_back((i-s.top().second));
        }
        
        s.push( make_pair(stocks[i], i) );
    }
    
    for(auto temp:result)
        cout<<temp<<" ";
}

int main()
{
    solve();
    return 0;
}
