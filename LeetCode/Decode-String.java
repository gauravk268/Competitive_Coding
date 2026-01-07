1class Solution {
2    public String decodeString(String s) {
3        StringBuilder sb = new StringBuilder();
4        Stack<Character> st = new Stack<>();
5
6        for(char c:s.toCharArray()){
7            if(c == ']'){
8                StringBuilder sb1 = new StringBuilder();
9                while(st.peek() != '['){
10                    sb1.append(st.pop());
11                }
12                st.pop();
13
14                StringBuilder sb2 = new StringBuilder();
15                while(!st.empty() && st.peek() - '0' <= 9 && st.peek() - '0' >=0){
16                    sb2.append(st.pop());
17                }
18                Integer k = Integer.parseInt(sb2.reverse().toString());
19                String str = sb1.reverse().toString();
20
21                while(--k > 0){
22                    sb1.append(str);
23                }
24
25                if(st.empty()){
26                    sb.append(sb1.toString());
27                }else{
28                    for(char a:sb1.toString().toCharArray()){
29                        st.push(a);
30                    }
31                }
32            }
33            else st.push(c);
34        }
35
36        StringBuilder sb3 = new StringBuilder();
37        while(!st.empty()){
38            sb3.append(st.pop());
39        }
40        sb.append(sb3.reverse());
41
42        return sb.toString();
43    }
44}