int Solution::maxProduct(const vector<int> &A) {
    int mn=A[0],mx=A[0],res=A[0];
    for(int i=1;i<A.size();i++){
        if(A[i]<0)
        swap(mn,mx);
        
        mn=min(mn*A[i],A[i]);
        mx=max(mx*A[i],A[i]);
        res=max(res,mx);
    }
    return res;
}
