#include<bits/stdc++.h>
using namespace std;

int factor[MAX] = { 0 };

// function to calculate number of factors 
int calculateNoOFactors(int n) 
{ 
    if (n == 1) 
        return 1; 
  
    int ans = 1; 
    int dup = factor[n]; 
    int c = 1; 
    int j = n / factor[n]; 
  
    while (j != 1) { 
        if (factor[j] == dup) 
            c += 1; 
        else { 
            dup = factor[j]; 
            ans = ans * (c + 1); 
            c = 1; 
        } 
  
        j = j / factor[j]; 
    } 
  
    ans = ans * (c + 1); 
    return ans; 
} 



int main(){
    int T;
    cin>>T;
    while(T--){
        long long int A, B, i, result;
        cin>>A>>B;

        if(A%B==0 || B%A==0)
            result = -1;
        
        else{
            int diff = abs(A-B);
            result = calculateNoOFactors(diff);

        }

        cout<<result<<"\n";
    }
    
    return 0;
}