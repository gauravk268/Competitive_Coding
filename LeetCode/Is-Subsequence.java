1class Solution {
2    public boolean isSubsequence(String s, String t) {
3        int a = t.length(), b = s.length();
4
5        if (b == 0)
6            return true;
7        if (a == 0)
8            return false;
9        if (s.equals(t))
10            return true;
11
12        if (s.charAt(b - 1) == t.charAt(a - 1)) {
13            return true && isSubsequence(s.substring(0, b - 1), t.substring(0, a - 1));
14        }
15
16        return isSubsequence(s, t.substring(0, a - 1));
17    }
18}