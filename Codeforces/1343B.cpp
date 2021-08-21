#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int i;
    long long n;
    cin>>n;
    
    if(n%4 != 0)
    {
        cout<<"NO\n";
        return;
    }
    
    cout<<"YES\n";
    for(i=1; i<=n/2; i++)
    {
        cout<<i*2<<" ";
    }
    
    for(i=1; i<n/2; i++)
    {
        cout<<i*2-1<<" ";
    }
    
    cout<<i*2-1 + (n/2)<<"\n";
    
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