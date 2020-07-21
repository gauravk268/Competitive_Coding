#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1e9+7

void solve()
{
    int n;
    cin>>n;
    
    unordered_set<int> a;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        
        a.insert(temp);
    }
    
    cout<<a.size()<<endl;
}

int main() {
	// your code goes here
	
	int t;
	cin>>t;

	while(t--)
	{
	    solve();
	}
	
	return 0;
}