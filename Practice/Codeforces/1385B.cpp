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
    vector<int> value;
    for(int i=0; i<2*n; i++){
        int temp;
        cin>>temp;
        
        if(a.find(temp)==a.end())
            value.push_back(temp);
        a.insert(temp);
    }
    
    for(auto &temp:value)
        cout<<temp<<" ";
    cout<<endl;
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