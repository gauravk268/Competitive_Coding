class Solution {
public:
    bool fun(vector<int> &piles, int h, long long k)
    {
        int res=0;
        for(int i=0; i<piles.size(); i++)
        {
            if(piles[i]%k == 0)
            {
                res += piles[i]/k;
            }
            else
            {
                res += (piles[i]/k) +1;
            }
        }
        
        return res<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long low=1, high=0, result=0;
        
        for(int i=0; i<n; i++)   high+=piles[i];
        
        while(low <= high)
        {
            long long mid=low + (high-low)/2;
            
            if(fun(piles, h, mid))
            {
                result = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        
        return (int)result;
    }
};