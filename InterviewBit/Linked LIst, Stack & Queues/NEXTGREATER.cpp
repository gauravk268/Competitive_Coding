vector<int> Solution::nextGreater(vector<int> &A) {
    int n=A.size();
    stack<int> s;

    vector<int> result(n);
    for(int i=n-1; i>=0; i--){
        while(s.size() && s.top()<=A[i]) s.pop();

        if(s.size())    result[i]=s.top();
        else result[i]= -1;

        s.push(A[i]);
    }

    return result;
}
