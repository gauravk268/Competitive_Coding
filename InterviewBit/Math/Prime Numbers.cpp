vector<int> Solution::sieve(int A) {
    if(A<2) return {};

    bool arr[A+1];
    for(int i=2; i<=A; i++) arr[i]=true;

    arr[0]=arr[1]=false;

    vector<int> result;
    for(int i=2; i<=A; i++){
        if(arr[i]){
            result.push_back(i);
            for(int j=i+i; j<=A; j+=i){
                arr[j]=false;
            }
        }
    }

    return result;
}
