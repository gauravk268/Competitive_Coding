#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1e9+7

void solve()
{
    int n;
    cin>>n;
    
    string value;
    cin>>value;
    
    int count=0, result=0;
    bool flag=true;
    vector<int> final;
    for(int i=0; i<n; i++)
    {
        if(value[i]=='x')
            count++;
            
        if(value[i]!='x' && count)
        {
            if(count>2)
            {
                flag=false;
                result += count-2;
            }
            count=0;
        }
        
        if(i==n-1 && count>2){
            result +=count-2;
            flag=false;
        }
    }

    flag?cout<<"0\n":cout<<result<<endl;
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