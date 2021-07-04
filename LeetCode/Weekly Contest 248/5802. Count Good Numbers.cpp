class Solution {
public:    
    long long fastPow(long long x, long long y)
    {
        long long res = 1;
        x = x % MOD;
        if (x == 0) return 0;

        while (y > 0)
        {
            if (y & 1)
                res = (res*x) % MOD;

            y = y>>1;
            x = (x*x) % MOD;
        }
        return res;
    }
    
    const int MOD=1e9+7;
    int countGoodNumbers(long long n) {
        int eCount=5, pCount=4;
        long long result=0, k=0;
        if(n&1){
            k=n/2;
            result=((fastPow(5, k+1)%MOD)*(fastPow(4, k)%MOD))%MOD;
        }else{
            k=n/2;
            result=((fastPow(5, k)%MOD)*(fastPow(4, k)%MOD))%MOD;
        }
        
        return result;
    }
};

