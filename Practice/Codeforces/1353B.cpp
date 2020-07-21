#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;
    
    vector<int> a(n), b(n);
    for(auto &temp:a)
        cin>>temp;
    
    for(auto & temp:b)
        cin>>temp;
        
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
        
    int ans=0;
    for(int i=0; i<n; i++)
    {
        (i<k)?ans+=max(a[i], b[i]):ans+=a[i];
    }
    
    cout<<ans<<"\n";
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