int Solution::maxArr(vector<int> &arr) 
{
    int n=arr.size();
    int max1=INT_MIN, max2=INT_MIN;
    int min1=INT_MAX, min2=INT_MAX;

    for(int i=0; i<n; i++)
    {
        max1 = max(max1, arr[i]+i);
        max2 = max(max2, arr[i]-i);
        min1 = min(min1, arr[i]+i);
        min2 = min(min2, arr[i]-i);
    }

    return max(max1-min1, max2-min2);
}
