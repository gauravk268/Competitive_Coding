#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int testCases;
    cin>>testCases;
    
    int priceBucket[50], fruitType[50], total[50];

    while(testCases--){
        int M, N, i, result=0, flag=1;
        cin>>N>>M;

        memset(priceBucket, 0, sizeof(priceBucket));
        memset(fruitType, 0, sizeof(fruitType));

        for(i=0; i<N; i++)
            cin>>fruitType[i];

        for(i=0; i<N; i++)
            cin>>priceBucket[i];

        memset(total, -1, sizeof(total));

        for(i=0; i<N; i++)
            total[fruitType[i]-1] += priceBucket[i];

        sort(total, total+M);

        if(total[M-1] == 0)
            result = 0;
        else{
            i=0;
            while(total[i] == 0)
                i++;

            result = total[i];

        }
        
        cout<<result<<endl;
    }

    return 0;
}