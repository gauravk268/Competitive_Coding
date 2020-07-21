#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1e9+7

void solve()
{
    int n, oddCount=0, evenCount=0;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        
        if(i%2==1 && temp%2!=1)  oddCount++;
        if(i%2==0 && temp%2==1)    evenCount++;
    }
    
    if(oddCount != evenCount){
        cout<<-1<<endl;
        return;
    }
    
    cout<<oddCount<<endl;
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