#include <bits/stdc++.h>
 
using namespace std;
int main()
{
  int n,x=0;
  cin>>n;
  
  while(n--)
  {  
      string s;
      cin>>s;
      
      if(s[0]=='+' && s[1]=='+' && s[2]=='X')
      x++;
      
       if(s[0]=='X' && s[1]=='+' && s[2]=='+')
       x++;
       
        if(s[0]=='-' && s[1]=='-' && s[2]=='X')
        x--;
        
         if(s[0]=='X' && s[1]=='-' && s[2]=='-')
         x--;
  }
  cout<<x;
    
    return 0;
}
