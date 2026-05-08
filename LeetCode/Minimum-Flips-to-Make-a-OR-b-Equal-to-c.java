1class Solution {
2    public int minFlips(int a, int b, int c) {
3        int result = 0;
4
5        while (a > 0 || b > 0 || c > 0) {
6            int a_bit = a & 1;
7            int b_bit = b & 1;
8            int c_bit = c & 1;
9
10            if (c_bit == 0) {
11                if ((a_bit == 1) && (b_bit == 1)) {
12                    result += 2;
13                } else if ((a_bit == 1) || (b_bit == 1)) {
14                    result++;
15                }
16            } else {
17                if ((a_bit == 0) && (b_bit == 0)) {
18                    result++;
19                }
20            }
21
22            a = a >> 1;
23            b = b >> 1;
24            c = c >> 1;
25        }
26
27        return result;
28    }
29}
30