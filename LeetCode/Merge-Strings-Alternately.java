1class Solution {
2    public String mergeAlternately(String word1, String word2) {
3        int i = 0, j = 0;
4        int n=word1.length(), m=word2.length();
5        StringBuilder result = new StringBuilder(n+m);
6
7        while (i < n || j < m) {
8            if (j >= m || result.length() % 2 == 0 && i < n) {
9                result.append(word1.charAt(i++));
10            } else if (i >= n || result.length() % 2 == 1 && j < m) {
11                result.append(word2.charAt(j++));
12            }
13        }
14
15        return result.toString();
16    }
17}