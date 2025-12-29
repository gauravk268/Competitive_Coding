1class Solution {
2    private int gcd(int a, int b) {
3        if (b == 0) {
4            return a;
5        } else
6            return gcd(b, a % b);
7    }
8
9    public String gcdOfStrings(String str1, String str2) {
10        int n = str1.length(), m = str2.length();
11
12        if ((str1 + str2).equals(str2 + str1)) {
13            return str1.substring(0, gcd(n, m));
14        }
15
16        return new String();
17    }
18}