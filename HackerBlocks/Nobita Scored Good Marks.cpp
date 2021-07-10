#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;  cin>>t;
  while(t--){
    int candies, num; cin>>candies>>num;

    int k=candies%num;
    if(abs(num-k) < k){
      cout<<num-k<<endl;
    }else{
      cout<<k<<endl;
    }
  }

	return 0;
}