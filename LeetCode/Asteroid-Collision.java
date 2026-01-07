1class Solution {
2    private Stack<Integer> helper(Stack<Integer> st, int i){
3        if(st.empty() || st.peek() < 0){
4            st.push(i);
5        }
6        else if(st.peek() > 0){
7            if(st.peek() < Math.abs(i)){
8                st.pop();
9                st = helper(st, i);
10            }
11            else if(st.peek() == Math.abs(i)){
12                st.pop();
13            }
14        }
15
16        return st;
17    }
18
19    public int[] asteroidCollision(int[] ast) {
20        Stack<Integer> st = new Stack<>();
21
22        for (int i : ast) {
23            if (i < 0) {
24                st = helper(st, i);
25            } else {
26                st.push(i);
27            }
28        }
29
30        int[] result = new int[st.size()];
31        for (int i = 0; i < st.size(); i++)
32            result[i] = st.get(i);
33
34        return result;
35    }
36}