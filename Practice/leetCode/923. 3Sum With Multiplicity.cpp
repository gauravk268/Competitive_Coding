class Solution {
  static const int MOD=1e9+7;
public:
    int threeSumMulti(vector<int>& arr, int target) {
      long long result=0;
      map<int, long> mp;
      for(int i=0; i<arr.size(); i++){
        mp[arr[i]]++;
      }
        
      for(auto a:mp){
        for(auto b:mp){
            int i=a.first, j=b.first, k=target-(i+j);
            if(mp.count(k)){
              if(i==j && j==k){
                result += (mp[i] * (mp[i]-1) * (mp[i]-2))/6;
              }else if(i==j && j!=k){
                result +=  ((mp[i] * (mp[i]-1))/2) * mp[k];
              }else if(i<j && j<k){
                result += (mp[i] * mp[j] * mp[k]);
              }
            }
        }
      }

      return (int)(result%MOD);
    }
};