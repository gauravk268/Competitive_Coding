const int MOD = 10000003;

bool isPossible(vector<int> &A, int at_most, int num)
{
    int currNum = 1, sum = 0;
    for (auto x : A){
        sum += x;
        if (sum > at_most){
            currNum++;
            sum = x;
        }

        if (currNum > num)  return false;
    }

    return true;
}

int Solution::paint(int A, int B, vector<int> &C)
{
    long long int low = *max_element(C.begin(), C.end()), high = 0, result=0, mid=0;
    if(C.size()<=A)     return (low*B)%MOD;

    for (auto x : C)
        high += x;

    while (low <= high){
        mid = low + (high - low) / 2;

        if (isPossible(C, mid, A)){
            high=mid-1;
            result=mid;
        }else{
            low=mid+1;
        }
    }

    return (result*B) % MOD;
}