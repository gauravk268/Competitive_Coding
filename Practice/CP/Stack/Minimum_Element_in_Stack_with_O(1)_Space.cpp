// Minimum Element in stack
// with O(1) space

#include<bits/stdc++.h>
using namespace std;

stack<int> s;
int minValue;

int pop()
{
    if(s.empty())
    {
        return -1;
    }
    else if(s.top()>=minValue)
    {
        int temp=s.top();
        s.pop();
        return temp;
    }
    else if(s.top()<minValue)
    {
        int temp=2*minValue-s.top();
        s.pop();
        int a=minValue;
        minValue=temp;
        return a;
    }
}

void push(int value)
{
    if(s.empty())
    {
        s.push(value);
        minValue=value;
        return;
    }
    else if(value>=minValue)
    {
        s.push(value);
        return;
    }
    else if(value<minValue)
    {
        int temp=2*value-minValue;
        s.push(temp);
        minValue=value;
        return;
    }
}

int minElement()
{
    return minValue;
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