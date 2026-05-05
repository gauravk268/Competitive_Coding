1class Solution {
2    public class Pair{
3        public int temp;
4        public int index;
5        public Pair(int a, int b){
6            this.temp = a;
7            this.index = b;
8        }
9    }
10    public int[] dailyTemperatures(int[] temps) {
11        Stack<Pair> st = new Stack<>();
12        int n = temps.length;
13        int[] res = new int[n];
14
15        res[n - 1] = 0;
16        st.push(new Pair(temps[n-1], n-1));
17
18        for (int i = n - 2; i >= 0; i--) {
19            while (!st.empty() && st.peek().temp <= temps[i]) {
20                st.pop();
21            }
22
23            if (st.empty()) {
24                res[i] = 0;
25            } else {
26                res[i] = st.peek().index-i;
27            }
28
29            st.push(new Pair(temps[i], i));
30        }
31
32        return res;
33    }
34
35}
36