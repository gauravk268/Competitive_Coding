1class Solution {
2    public boolean isVowel(char c) {
3        return ("aeiouAEIOU".indexOf(c) != -1);
4    }
5
6    public String reverseVowels(String s) {
7        StringBuilder sb = new StringBuilder(s);
8
9        int n = s.length();
10        int i = 0, j = s.length() - 1;
11
12        while (i < j) {
13            while (i < n && !this.isVowel(s.charAt(i))) {
14                i++;
15            }
16
17            while (j >= 0 && !this.isVowel(s.charAt(j))) {
18                j--;
19            }
20
21            if(i<n && j>=0){
22                char c = s.charAt(i);
23                sb.setCharAt(i, s.charAt(j));
24                sb.setCharAt(j, c);
25                i++;
26                j--;
27            }
28        }
29
30        return sb.toString();
31    }
32}