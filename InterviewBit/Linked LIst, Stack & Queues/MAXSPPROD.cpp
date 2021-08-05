int Solution::maxSpecialProduct(vector<int> &A) {
    int n=A.size();
    long long int l[n], r[n];
    stack<int> s;

    for(int i=0; i<n; i++){
        while(s.size() && A[s.top()]<=A[i]) s.pop();
        
        if(s.size())   l[i]=s.top();  
        else l[i]=0;

        s.push(i);
    }

    while(s.size()) s.pop();
    for(int i=n-1; i>=0; i--){
        while(s.size() && A[s.top()]<=A[i]) s.pop();
        
        if(s.size())   r[i]=s.top();    
        else r[i]=0;

        s.push(i);
    }

    long long int result= -1;
    for(int i=0; i<n; i++){
        result = max(result, l[i]*r[i]);
    }

    return result%1000000007;
}
