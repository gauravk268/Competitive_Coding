#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCases;
    cin>>testCases;
    
    while(testCases--){
        int rInitial, cInitial;
        cin>>rInitial>>cInitial;

        queue <int> chess;
        
        int steps = 64;
        while(steps){
            for(int i=1; i<=8; i++){
                for(int j=1; j<=8; j++){
                    if((rInitial - i) == (cInitial - j)){
                        cout<<i<<" "<<j<<endl;
                        steps--;
                    }
                    if(steps == 0)
                        break;
                }
            }
        }
    }
    
    return 0;
}