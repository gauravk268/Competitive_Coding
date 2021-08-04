stack<int> s, minS;

MinStack::MinStack() {
    while(s.size()) s.pop();
    while(minS.size())  minS.pop();
}

void MinStack::push(int x) {
    s.push(x);
    if(minS.size()){
        if(minS.top() > x)  minS.push(x);
        else minS.push(minS.top());    
    }else{
        minS.push(x);
    }
}

void MinStack::pop() {
    if(s.size()){
        s.pop();
        minS.pop();
    }
}

int MinStack::top(){
    if(s.empty())   return -1;
    return s.top();
}

int MinStack::getMin() {
    if(minS.empty())    return -1; 
    return minS.top();
}