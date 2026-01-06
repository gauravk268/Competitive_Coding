1class Solution {
2    public boolean closeStrings(String word1, String word2) {
3        int n = word1.length(), m = word2.length();
4
5        if (n != m)
6            return false;
7
8        Set<Character> st = new HashSet<>();
9        int[] fa = new int[26], fb = new int[26];
10        for (int i = 0; i < 26; i++) {
11            fa[i] = 0;
12            fb[i] = 0;
13        }
14        for (char i : word1.toCharArray()) {
15            st.add(i);
16            fa[i - 'a']++;
17        }
18
19        for (char i : word2.toCharArray()) {
20            if (st.add(i)) {
21                return false;
22            }
23            fb[i - 'a']++;
24        }
25
26        Arrays.sort(fa);
27        Arrays.sort(fb);
28
29        for (int i = 0; i < 26; i++) {
30            if (fa[i] != fb[i])
31                return false;
32        }
33
34        return true;
35    }
36}