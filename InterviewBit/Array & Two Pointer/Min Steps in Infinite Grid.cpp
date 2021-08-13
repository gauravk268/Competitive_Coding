int disCount(int x2, int y2, int x1, int y1)
{
    return max(abs(x2-x1), abs(y2-y1));
}

int Solution::coverPoints(vector<int> &A, vector<int> &B) 
{
    int result = 0;
    
    for(int i=1; i<A.size(); i++)
    {
        result += disCount(A[i], B[i], A[i-1], B[i-1]);
    }

    return result;
}
