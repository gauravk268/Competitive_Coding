#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1e9+7

void solve()
{
    int n;
    cin>>n;
    
    vector<int> student;
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        
        auto j=find(student.begin(), student.end(), temp);
        
        if(j==student.end())
            student.push_back(temp);
        else
            student.erase(j);
    }
    
    sort(student.begin(), student.end());
    
    int result=0;
    for(int i=0; i<student.size(); i+=2)
        result += student[i+1]-student[i];
    
    cout<<result<<endl;
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