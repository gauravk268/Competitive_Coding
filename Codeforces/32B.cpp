#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1e9+7

void solve()
{
    string borze;
    cin>>borze;
    
    vector<int> result;
    int n=borze.length();
    for(int i=0; i<n; i++)
    {
        if(borze[i] == '.')
            result.push_back(0);
        
        else if(borze[i] == '-')
        {
            if(i<n-1 && borze[i+1]=='.')
                result.push_back(1);
            if(i<n-1 && borze[i+1]=='-')
                result.push_back(2);
            i++;
        }
    }
    
    for(auto &value: result)
        cout<<value;
}

int main() {
	// your code goes here
	
	int t=1;
// 	cin>>t;

	while(t--)
	{
	    solve();
	}
	
	return 0;
}