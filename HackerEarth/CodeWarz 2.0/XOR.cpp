#include <bits/stdc++.h> 
using namespace std; 

// Function to calculate xor 
long long int computeXOR(const int n) 
{
	switch(n & 3)
	{ 
	case 0: return n;
	case 1: return 1;
	case 2: return n + 1; 
	case 3: return 0;
	} 
} 
 
int main() 
{ 
	int testCases;
    cin>>testCases;
    
    while(testCases--){
        int q;
        cin>>q;
        
        while(q--){
            long long int a, b;
            cin>>a>>b;
            
            long long int xor1 = computeXOR(a-1);
            long long int xor2 = computeXOR(b);

            long long ans = xor1 ^ xor2;
            
            cout<<ans<<endl;
        }
    }
} 
