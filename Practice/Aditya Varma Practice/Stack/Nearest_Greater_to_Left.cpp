#include<bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> values={4, 2, 1, 0, 0, 3, 1}, result;
    stack<int> temp;
    
    for(int i=0; i<values.size(); i++)
    {
        if(temp.empty())
        {
            result.push_back(-1);
        }
        else if(temp.top()<=values[i])
        {
            while(!temp.empty() and temp.top()<=values[i])
                temp.pop();
                
            if(temp.empty())    result.push_back(-1);
            else    result.push_back(temp.top());
        }
        else    result.push_back(temp.top());
        
        temp.push(values[i]);
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