#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1e9+7

void solve()
{
    int n;
    cin>>n;
    
    vector<int> a(n), b(n);
    for(auto &temp:a)
        cin>>temp;
    
    sort(a.begin(), a.end());
    
    int min=MOD;
    
    for(int i=1; i<n; i++)
        if(min > a[i]-a[i-1])   min = a[i]-a[i-1];
        
    cout<<min<<endl;
    
}

int main() {
	// your code goes here
	
	int t, i=1;
	cin>>t;

	while(t--)
	{
	    solve();
	}
	
	return 0;
}