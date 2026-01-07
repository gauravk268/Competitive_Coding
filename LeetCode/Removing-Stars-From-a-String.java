1class Solution {
2    public String removeStars(String s) {
3        Stack<Character> st = new Stack<>();
4        for(char c:s.toCharArray()){
5            if(c != '*'){
6                st.push(c);
7            }
8            else{
9                st.pop();
10            }
11        }
12
13        StringBuilder sb = new StringBuilder();
14        while(!st.empty()){
15            sb.append(st.pop());
16        }
17
18        return sb.reverse().toString();
19    }
20}