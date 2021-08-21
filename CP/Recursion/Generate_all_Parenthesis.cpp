#include<bits/stdc++.h>
using namespace std;

void solve(string temp, int o, int c)
{
    if(o==0 && c==0)
    {
        cout<<temp<<" ";
        return;
    }
    
    if(o==c && o && c)
    {
        temp+="(";
        
        solve(temp, o-1, c);
    }
    else if(c>o && o>=1)
    {
        string temp1=temp;
        
        temp+="(";
        solve(temp, o-1, c);
        
        temp1+=")";
        solve(temp1, o, c-1);
    }
    else if(!o)
    {
        while(c--)
            temp+=")";
        
        solve(temp, 0, 0);
    }
    
    return;
}

int main()
{
    int t=1;
    // cin>>t;
    
   while(t--)
   {
        int n=3;
        string temp="";
        
        solve(temp, n, n);
   }
    return 0;
}