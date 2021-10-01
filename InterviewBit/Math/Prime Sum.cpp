vector<bool> sievearr;
void sieve(int A){
    sievearr.resize(A);
    for(int i=0;i<A;i++){
         sievearr[i]=true;
    }
    sievearr[0] =false;
    sievearr[1]=false;
    sievearr[2]=true;
for(int i =2;i<A;i++){
    if(sievearr[i] == true){
        for(int j=2;j*i<A;j++){
                sievearr[j*i]=false;
            }
        }
    }
}

vector<int> Solution::primesum(int A) {
    sieve(A);
    vector<int> res;
    for(int i = 2; i<=sqrt(A); i++){
        if(sievearr[i] == true && sievearr[A-i] == true){
            res.push_back(i);
            res.push_back(A-i);
            return res;
        }
    }
}
