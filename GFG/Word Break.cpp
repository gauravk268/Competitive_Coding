// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    map<string, int> mp;

    bool fun(string a)
    {
        if(mp[a])   return true;
        
        for(int i=1; i<a.size(); i++)
        {
            if(mp[a.substr(0, i)] && fun(a.substr(i)))
                return true;
        }
        
        return false;
    }

    int wordBreak(string A, vector<string> &B) 
    {
        for(int i=0; i<B.size(); i++)
        {
            mp[B[i]]=1;
        }
        
        return fun(A);
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends