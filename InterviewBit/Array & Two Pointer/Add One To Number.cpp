vector<int> Solution::plusOne(vector<int> &A) {
    reverse(A.begin(), A.end());

    int carry=0;
    A[0]++;
    for(int i=0; i<A.size(); i++)
    {
        A[i]+=carry;
        carry /= 10;

        carry += A[i]/10;
        A[i]%=10;
    }

    while(carry)
    {
        A.push_back(carry%10);
        carry /= 10;
    }

    while(A[A.size()-1]==0) A.pop_back();

    reverse(A.begin(), A.end());
    return A;
}
