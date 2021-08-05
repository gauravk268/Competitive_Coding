int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    int n=A.size();

    for(int i=0; i<n; i++){
        int b, a;
        if(A[i]=="+"){
          b = s.top(); s.pop();
          a = s.top(); s.pop();
          s.push(a+b);
        }
        else if(A[i]=="-"){
          b = s.top(); s.pop();
          a = s.top(); s.pop();
          s.push(a-b);
        }
        else if(A[i]=="*"){
          b = s.top(); s.pop();
          a = s.top(); s.pop();
          s.push(a*b);
        }
        else if(A[i]=="/"){
          b = s.top(); s.pop();
          a = s.top(); s.pop();
          s.push(a/b);
        }
        else{
            s.push(stoi(A[i]));
        }
    }

    return s.top();
}
