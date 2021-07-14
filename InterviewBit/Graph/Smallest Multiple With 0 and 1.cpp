int mod(string a, int k){
  int r=0;

  for(int i=0; i<a.length(); i++){
    r=r*10+(a[i]-'0');
    r%=k;
  }

  return r;
}

string Solution::multiple(int A) {
  if(A==1)  return "1";

  queue<string> q;
  q.push("1");

  while(q.size()){
    string cur=q.front();
    q.pop();

    if(!mod(cur, A))  return cur;
    q.push(cur+"0");
    q.push(cur+"1");
  }

  return -1;
}
  