class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        
        long long fResult=INT_MAX, tResult=0;
        for(int i=0; i<n-m+1; i++){
            tResult = a[i+m-1]-a[i];
            fResult = min(fResult, tResult);
        }
        
        return fResult;
    }   
};