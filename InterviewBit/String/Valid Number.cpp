int Solution::isNumber(const string A) {
    int lw = 0, hi = A.size()-1;
    while (A[lw]==' ') lw++;
    while (A[hi]==' ') hi--;
    if (lw>hi || A[hi]<'0' || A[hi]>'9') return 0;
    bool next_neg = true, next_e = false, next_dot = true, e = false;
    for (int i=lw; i<=hi; i++){
        if (A[i]=='-' && next_neg){
            next_e = false;
            next_neg = false;
        }
        else if (A[i]=='.' && next_dot){
            next_dot = false;
            next_e = false;
            next_neg = false;
        }
        else if (A[i]=='e' && next_e){
            e = true;
            next_e = false;
            next_neg = true;
            next_dot = false;
        }
        else if (A[i]>='0' && A[i]<='9'){
            if (!e) next_e = true;
            next_neg = false;
        }
        else {
            return 0;
        }
    }
    return 1;
}
