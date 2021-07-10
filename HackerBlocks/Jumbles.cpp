#include<bits/stdc++.h>
using namespace std;

int main(){
  string a, b;  cin>>a>>b;

  if(a.length()!=b.length()){
    cout<<"False\n";
    return 0;
  }else{
    int arr[26];
    memset(arr, 0, sizeof(arr));

    for(auto x:a){
      arr[x-'a']++;
    }

    for(auto x:b){
      arr[x-'a']--;
    }

    for(int i=0; i<26; i++){
      if(arr[i]!=0){
        cout<<"False\n";
        return 0;
      }
    }
  }

  cout<<"True\n";
  return 0;
}