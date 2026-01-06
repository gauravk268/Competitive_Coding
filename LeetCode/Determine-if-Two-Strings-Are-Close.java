1class Solution {
2    public boolean closeStrings(String word1, String word2) {
3        if (word1.length() != word2.length())
4            return false;
5
6        int[] a = new int[26], b = new int[26];
7
8        for (char c : word1.toCharArray()) {
9            a[c - 'a']++;
10        }
11
12        for (char c : word2.toCharArray()) {
13            b[c - 'a']++;
14        }
15
16        for (int i = 0; i < 26; i++) {
17            if ((a[i] == 0 && b[i] != 0) || (a[i] != 0 && b[i] == 0)) {
18                return false;
19            }
20        }
21
22        Arrays.sort(a);
23        Arrays.sort(b);
24
25        return Arrays.equals(a, b);
26    }
27}