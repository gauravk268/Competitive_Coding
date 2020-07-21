#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int a, b;
	cin>>a>>b;
	
	bool flag=true;
	for(int i=0; i<a; i++)
	{
	    for(int j=0; j<b; j++)
	    {
	        if(i%2)
	        {
	            if(flag)
	            {
	                if(j==b-1){
	                    cout<<"#";
	                    flag = false;
	               }
	                else
	                    cout<<".";
	            }
	            else
	            {
	                if(j==0){
	                    cout<<"#";
	               }
	                else{
	                    cout<<".";
	                    if(j==b-1)
	                        flag = true;
	                }
	            }
	        }
	        else
	            cout<<"#";
	    }
	    cout<<"\n";
	}
	
	return 0;
}