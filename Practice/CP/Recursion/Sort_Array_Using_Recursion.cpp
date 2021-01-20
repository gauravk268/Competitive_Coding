#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &value, int n){
    if(value.size()==0 || value[value.size()-1] <= n){
        value.push_back(n);
        return;
    }
    
    int val = value[value.size()-1];
    value.pop_back();
    insert(value, n);
    value.push_back(val);
    return;
}

void sortValue(vector<int> &value){
    if(value.size()==1)    return;
    
    int val = value[value.size()-1];
    value.pop_back();
    sortValue(value);
    
    insert(value, val);
    return;
}

int main() {
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        vector<int> value(n);
        for(int i=0; i<n; i++)  cin>>value[i];
        
        sortValue(value);
        
        for(int i=0; i<n; i++)  cout<<value[i]<<" ";
        cout<<"\n";
    }
	return 0;
}