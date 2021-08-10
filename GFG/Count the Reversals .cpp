// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    stack<char> sk;
    
    int result=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='}'){
            if(sk.empty()){
                result++;
                sk.push('{');
            }else   sk.pop();
        }else{
            if(sk.size()+i >= s.length()){
                sk.pop();
                result++;
            }else sk.push(s[i]);
        }
    }
    
    if(sk.size())    return -1;
    
    return result;
}