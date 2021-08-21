#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;

	while(t--)
	{
		long long a;
		cin>>a;
		
		if(a<=2)
		    cout<<0<<"\n";
		else if(a%2)
		    cout<<(a/2)<<"\n";
        else
            cout<<(a/2)-1<<"\n";
	}
	
	return 0;
}