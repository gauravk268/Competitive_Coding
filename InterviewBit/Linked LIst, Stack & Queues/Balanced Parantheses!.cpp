int Solution::solve(string A) {
    stack<char> s;
    for(auto &x:A){
        if(x=='('){
            s.push(x);
        }else if(x==')'){
            if(s.empty())   return false;
            else s.pop();
        }else   return false;
    }

    return s.empty();
}
