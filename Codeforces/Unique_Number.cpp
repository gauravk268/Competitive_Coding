#include<bits/stdc++.h>
using namespace std;
 
 void solvebolte(){
            int n;
            cin>>n;
            if(n>45)
            {
                cout<<-1<<endl;
                return;
            }
            string s="";
            for(int i=9;i>=1;i--)
            {
                if(n<=9 && n<=i){
                    s+=to_string(n);
                    n=0;
                    break;
                }
                else{
                    s+=to_string(i);
                    n-=i;
                }
            }
            if(n)
            {
                cout<<-1<<endl;
                return;
            }
            reverse(s.begin(),s.end());
            cout<<s<<endl;
        }
        int main(){
          
            int t;
            cin>>t;
        
            while(t--)
            {
                solvebolte();
            }
            return 0;
        }
