#include<bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> values={1, 3, 0, 0, 1, 2, 4}, result;
    stack<int> temp;
    
    for(int i=values.size()-1; i>=0; i--)
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
    
    reverse(result.begin(), result.end());
    for(auto temp:result)
        cout<<temp<<" ";
}

int main()
{
    solve();
    // test();
    
    return 0;
}