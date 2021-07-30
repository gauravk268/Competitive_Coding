vector<int> Solution::allFactors(int A) {
    if(A<2) return {A};

    vector<int> result;
    for(int i=1; i*i<=A; i++){
        if(i*i==A)  result.push_back(i);
        else if(A%i == 0){
            result.push_back(i);
            result.push_back(A/i);
        }
    }

    sort(result.begin(), result.end());
    return result;
}
