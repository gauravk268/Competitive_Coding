int Solution::longestConsecutive(const vector<int> &A) {
    set<int> values;
    for(auto &x:A){
        values.insert(x);
    }

    int last=*values.begin(), count=1, tmp=1;
    values.erase(values.begin());

    for(auto &x:values){
        if(abs(last-x)==1){
            tmp++;
            count=max(count, tmp);
        }else tmp=1;

        last=x;
    }

    count=max(count, tmp);
    return count;
}
