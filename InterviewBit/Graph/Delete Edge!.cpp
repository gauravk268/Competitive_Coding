long long int ans, sum, mod=1e9+7;

long long int  sol(int x, int par, vector<int>g[], vector<int> &A){
    long long int temp=0;

    for(auto i:g[x]){
      if(i!=par)  temp+=sol(i, x, g, A);
    }
    temp+=A[x-1];

    ans=max(ans,((temp%mod)*(sum-temp)%mod)%mod);
    return temp;
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int n=A.size();
    vector<int> g[n+1];
    
    for(auto i:B){
      g[i[0]].push_back(i[1]);
      g[i[1]].push_back(i[0]);
    }
    
    sum=ans=0;
    for(auto i:A) sum+=i;
    sol(1, -1, g, A);
    
    return ans%mod;
}