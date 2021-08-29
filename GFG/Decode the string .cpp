// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<int> s1;
        stack<string> s2;
        
        string tmp="", result="";
        
        for(int i=0; i<s.length(); i++)
        {
            if(isdigit(s[i]))
            {
                int count=0;
                while(isdigit(s[i]))
                {
                    count *= 10;
                    count += s[i]-'0';
                    i++;
                }
                i--;
                s1.push(count);
            }
            else if(s[i]==']')
            {
                tmp="";
                while(s2.size() && s2.top()!="[")
                {
                    tmp = s2.top() + tmp;
                    s2.pop();
                }
                
                if(s2.size() && s2.top()=="[")  s2.pop();
                
                int k=s1.top(); s1.pop();
                while(k--)
                {
                    result += tmp;
                }
                
                s2.push(result);
                result = "";
            }
            else
            {
                string tmp="";
                tmp += s[i];
                s2.push( tmp );
            }
            
        }
        
        while(s2.size())
        {
            result = s2.top() + result;
            s2.pop();
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends