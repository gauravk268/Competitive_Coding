1class Solution {
2    public static int[] dailyTemperatures(int[] temps) {
3        Stack<Integer> st = new Stack<>();
4        int[] res = new int[temps.length];
5
6        for (int i = 0; i < temps.length; i++) {
7            while (!st.empty() && temps[i] > temps[st.peek()]) {
8                int k = st.pop();
9                res[k] = i - k;
10            }
11
12
13            st.push(i);
14        }
15
16        return res;
17    }
18
19}
20