#include <iostream>
#include <string.h>
#include <bitset>
#include<math.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)

const int MOD = 1e9+7;
const int SIZE_INT = 16;

//To print binary equivalent of a binary number
void printBinary(unsigned n)
{
    unsigned i;
    for (i = 1 << 15; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    cout << "\n";
}

// Fast way to calculate power of a large number
ll powerFast(ll a, ll b)
{
    // 3^10 == (3*3)^(10/2)
    // keep on repeating until the power cannot be divided

    a%=MOD;
    ll result =1;
    while(b>0){
        if(b%2 == 1){
            result *= a;
            result %= MOD;
        }

        a*=a;   a%=MOD;
        b/=2;
    }
    
    return result;
}

void solve()
{
    ll N, result=0;
    cin>>N;
    
    bool string[N];
    char temp;
    int countA[N], countB[N], numA=0, numB=0;
    
    MEM(string, 0, N);
    MEM(countA, 0, N);
    MEM(countB, 0, N);
    
    FoR(i, N)
    {
        cin>>temp;
        if(temp == 'A')
        {
            string[i] = 1;
            numA++;
        }
        else if(temp == 'B')
        {
            numB++;
            string[i]=0;
        }
        else    string[i]=-1;
        
        countA[i] = numA;
        countB[i] = numB;
    }
    
    if(N == 1)      result = 0;
    else if(numA == 0 || numB == 0)     result = 0;
    else
    {
        result = MOD;
        int cost;
        FoR(i, N)
        {
            //AABBAABBAAA
            //12223444567
            //00122234444
            
            //BBBBBBBBA
            //000000001
            //123456788
            
            if(string[i]==0)
                cost = countB[i] + numA - countA[i];
            if(string[i]==1)
                cost = countB[i] + numA - countA[i];
            
            if(result>cost)     result = cost;
        }
    }
    
    if(numA>numB){
        if(result > numB)   result = numB;
    }
    else if(result > numA)  result = numA;
        
    cout<<result<<"\n";
}

int main()
{
    //solve();

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        solve();
    }
    return 0;
}