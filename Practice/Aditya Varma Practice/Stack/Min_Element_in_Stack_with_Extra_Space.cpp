// Minimum Element in stack
// with extra space

#include<bits/stdc++.h>
using namespace std;

stack<int> s, ss;

int pop()
{
    if(s.empty())   return -1;
    
    if(s.top()==ss.top())
    {
        ss.pop();
        int t=s.top();
        s.pop();
        return t;
    }
    
    int t=s.top();
    s.pop();
    return t;
}

void push(int value)
{
    if(ss.empty() || value<ss.top())
    {
        s.push(value);
        ss.push(value);
        return;
    }
    
    s.push(value);
}

int minElement()
{
    if(ss.empty())  return -1;
    
    return ss.top();
}

void solve()
{
    vector<int> value={5, 8, 7, 6, 2, 4, 1, 6, 9};
    for(int i=0; i<value.size(); i++)
    {
        push(value[i]);
        cout<<value[i]<<" "<<minElement()<<endl;
    }
    cout<<endl;
    
    for(int i=0; i<value.size(); i++)
    {
        cout<<pop()<<" "<<minElement()<<endl;
    }
}

int main()
{
    solve();
    return 0;
}