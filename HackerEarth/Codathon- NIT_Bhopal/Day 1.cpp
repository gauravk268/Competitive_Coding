#include<bits/stdc++.h>
using namespace std;
 
int main(){
	long long int N, K, initial, last, temp;
	cin>>N>>K>>temp;
	
	while(temp<=K){
			cin>>temp;
			N--;
	}
	initial = N;
	
	while(N--){
		if(temp>K)
            last = N;
        cin>>temp;
	}
	
	cout<<(initial - last);
}
