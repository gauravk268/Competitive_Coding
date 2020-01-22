#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[3];

int isPrime(long long int n){
    for(int i=1; i*i<n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}


void primeFactors(int n) {   
    while (n % 2 == 0)  {  
        cout << 2 << " ";  
        n = n/2;  
    }  
   
    for (int i = 3; i <= sqrt(n); i = i + 2)  {  
        while (n % i == 0)  {  
            cout << i << " ";  
            n = n/i;  
        }  
    }
}  


void ans(long long int a,long long int b,long long int c){
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
}

int main() {
    int T, i;
    cin>>T;
    while(T--){
        long long int n, result;
        int flag=0;
        cin>>n;
        
        
        if(isPrime(n) || n < 24)
            flag = 0;
        else if()
        
        
           
        if(flag){
            cout<<"YES\n";
            for(i=0; i<3; i++)
                cout<<arr[i]<<"\t";
        }    
        else    cout<<"NO\n";
    }
    return 0;
}

