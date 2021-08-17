int Solution::maxSubArray(const vector<int> &A) {
    int maxSoFar=INT_MIN, maxEndHere=0;

    for(int i=0; i<A.size(); i++)
    {
        maxEndHere += A[i];
        maxSoFar = max(maxSoFar, maxEndHere);

        if(maxEndHere < 0)
        {
            maxEndHere = 0;
        }
    }

    return maxSoFar;
}
