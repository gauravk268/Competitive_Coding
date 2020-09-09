#include<bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> values={1, 3, 0, 0, 1, 2, 4, 3}, result;
    stack<int> s;
    
    for(int i=0; i<values.size(); i++)
    {
        if(s.empty())
            result.push_back(-1);
            
        else if(s.top()<values[i])
            result.push_back(s.top());
            
        else if(s.top()>=values[i])
        {
            while(!s.empty() && s.top()>=values[i])
                s.pop();
                
            if(s.empty())   result.push_back(-1);
            else    result.push_back(s.top());
        }
        
        s.push(values[i]);
    }
    
    for(auto temp:result)
        cout<<temp<<" ";
}

int main()
{
    solve();
    // test();
    
    return 0;
}