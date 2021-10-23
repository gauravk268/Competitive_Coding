#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
   string s;
   cin>>s;
   
   int n=s.length();
 
  vector<int>a;
  int i=0;
  while(i<n)
  {
     a.push_back(s[i]);
      i=i+2;
  }
  sort(a.begin(),a.end());
  int j=0;
  int k=0;
 while(j<n)
 {
     s[j]=a[k];
     j=j+2;
     k++;
 }
   for(int i=0;i<n;i++)
   cout<<s[i];
   
   
   return 0;
}
