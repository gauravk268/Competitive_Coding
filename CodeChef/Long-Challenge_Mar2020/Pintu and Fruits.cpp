#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int testCases;
    cin>>testCases;

    int priceBucket[55], fruitType[55], total[55];

    while(testCases--){
        int M, N, i, result=0;
        cin>>N>>M;

        memset(priceBucket, 0, sizeof(priceBucket));
        memset(fruitType, 0, sizeof(fruitType));
        memset(total, -1, sizeof(total));

        for(i=0; i<N; i++){
        	cin>>fruitType[i];
        	total[fruitType[i]]=0;
		}
            

        for(i=0; i<N; i++){
        	cin>>priceBucket[i];
        	total[fruitType[i]] += priceBucket[i] ;
		}

        sort(total, total+55);
        i=0;
        while(total[i] < 0)
            i++;
        result = total[i];
        
        cout<<result<<endl;
    }

    return 0;
}