int Solution::braces(string A) {
    if(A[0]=='(' && A.length()<=3)  return true;

    stack<char> s;

    char last=',';
    for(int i=0; i<A.length(); i++){
        if(A[i]==')'){
            while(s.top()!='(' ){
                last = s.top();
                s.pop(); 
            }

            if(s.top()==last)   return true;
            else{
                last = s.top();
                s.pop();
            }
        }else{
            if(A[i]=='(' && i+2<A.length() && A[i+2]==')')  return true;
            
            s.push(A[i]);
        }
    }

    return false;
}
