#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int testCase;
    cin>>testCase;
    
    while(testCase--){
        int flag=0, index;
        long long int numCoins, fare;
        cin>>numCoins>>fare;
        
        int valueCoins[numCoins], ans[numCoins];
        memset(ans, 0, sizeof(ans));
        for(int i=0; i<numCoins; i++){
            cin>>valueCoins[i];
            
            if(!flag)
                if(fare%valueCoins[i] != 0){
                    flag=1 ;
                    index = i;
                }
        }
        
        if(flag){
            cout<<"YES ";
            for(int i=0; i<numCoins; i++){
                if(i == index)
                    valueCoins[i] = (fare/valueCoins[i]) + 1;
                else
                    valueCoins[i] = 0;
                    
                cout<<valueCoins[i]<<" ";
            }
            
            cout<<"\n";
        }
        
        else{
            int value=0, temp = 1;
            
            for(int i=numCoins-1; i>=0; i--){
                
                if((fare%valueCoins[i]) == 0){
                    value = (fare/valueCoins[i]) - 1;
                    fare -= value * valueCoins[i];
                    ans[i] = value;
                }
                
                else{
                    value = (fare/valueCoins[i]) + 1;
                    fare -= value * valueCoins[i];
                    ans[i] = value;
                    break;
                }
            }
            
            if(fare < 0){
                cout<<"YES ";
                for(int i=0; i<numCoins; i++)
                    cout<<ans[i]<<" ";
            }
            
            else if(fare == 0){
                cout<<"NO";
            }
            
            else if(fare > 0){
                if((fare%valueCoins[0]) == 0){
                    cout<<"NO";
                }
                
                else{
                    cout<<"YES ";
                    for(int i=0; i<numCoins; i++)
                        cout<<ans[i]<<" ";
                }
                    
            }
            
            cout<<"\n";
        }
    }
    return 0;
}