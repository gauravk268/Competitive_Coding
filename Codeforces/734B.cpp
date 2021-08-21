#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1e9+7

void solve()
{
    vector<int> value(4);
    for(int i=0; i<4; i++)
        cin>>value[i];
        
    int flagLarge = min(value[2], value[3]);
    
    int numLarge = min(value[0], flagLarge);
    value[0] -= min(value[0], flagLarge);
    
    int numSmall = min(value[0], value[1]);
    
    cout<<256*numLarge + 32*numSmall<<endl;
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