#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1e9+7

void solve()
{
    string a, b, c, d;
    cin>>a>>b>>c;
    
    unordered_map<char, char> type;
    for(int i=0; i<a.length(); i++)
        type[ a[i] ] = b[i];
        
    d.clear();
    for(int i=0; i<c.length(); i++)
    {
        if(isalpha(c[i]))
        {
            if(islower(c[i]))
                d.push_back( type[tolower(c[i])] );
            else
                d.push_back( toupper( type[tolower(c[i])] ) );
        }
        else    d.push_back(c[i]);
    }
    
    cout<<d;
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