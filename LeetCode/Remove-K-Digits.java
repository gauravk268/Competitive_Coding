1class Solution {
2    public String removeKdigits(String num, int k) {
3        int n = num.length();
4        Stack<Character> st = new Stack<>();
5
6        for (char c : num.toCharArray()) {
7            while (!st.empty() && k > 0 && st.peek() > c) {
8                st.pop();
9                k--;
10            }
11
12            if (!st.empty() || c != '0') {
13                st.push(c);
14            }
15        }
16
17        while (!st.empty() && k-- > 0) {
18            st.pop();
19        }
20
21        if (st.empty())
22            return "0";
23
24        StringBuilder sb = new StringBuilder();
25        while (!st.empty()) {
26            sb.append(st.pop());
27        }
28
29        return sb.reverse().toString();
30    }
31}