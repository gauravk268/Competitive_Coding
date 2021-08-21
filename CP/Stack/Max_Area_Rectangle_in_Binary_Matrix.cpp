//Maximum area rectangle in Binary Matrix

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

int maxAreaHist(vector<int> &values)
{
    vector<int> left, right;
    left=NSL(values);
    right=NSR(values);
    int max=0;
    
    for(int i=0; i<values.size(); i++)
    {
        int area=(right[i]-left[i]-1)*values[i];
        
        if(area>max)    max=area;
    }
    
    return max;
}

void solve()
{
    vector<vector<int>> matrix={{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    vector<int> present, previous=matrix[0];
    
    int max=maxAreaHist(previous);
        
    for(int i=1; i<matrix.size(); i++)
    {
        present=matrix[i];
        
        for(int j=0; j<present.size(); j++)
        {
            if(present[j])
                present[j]+=previous[j];
        }
        
        int temp=maxAreaHist(previous);
        if(temp>max)    max=temp;
        
        previous=present;
    }
    
    cout<<max<<endl;
}

int main()
{
    solve();
    return 0;
}
