#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;  cin>>t;
    while(t--){
        string x;   cin>>x;
        stack<int> s;
        string result="";
        for(int i=0; i<=x.length(); i++){
            s.push(i+1);
            if((x[i]-'0')%2==0){
                while(s.size()){
                    result+= s.top()+'0';
                    s.pop();
                }
            }
        }

        while(s.size()){
            result+= s.top()+'0';
            s.pop();
        }

        cout<<result<<"\n";
    }

    return 0;
}