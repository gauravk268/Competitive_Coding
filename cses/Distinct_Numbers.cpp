#include <bits/stdc++.h>
using namespace std;
int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n, temp;  cin>>n;
  set<int> s;
  while(n--){
    cin>>temp;
    s.insert(temp);
  }
  cout<<s.size();
  return 0;
}