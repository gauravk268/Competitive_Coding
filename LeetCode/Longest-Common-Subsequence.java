1class Solution {
2    int[][] mem;
3
4    private int helper(String a, String b, int i, int j) {
5        if (i < 0 || j < 0)
6            return 0;
7
8        if (mem[i][j] != 0)
9            return mem[i][j];
10
11        int result = 0;
12        if (a.charAt(i) == b.charAt(j)) {
13            result = 1 + helper(a, b, i - 1, j - 1);
14        } else {
15            result = Math.max(helper(a, b, i - 1, j), helper(a, b, i, j - 1));
16        }
17
18        return mem[i][j] = result;
19    }
20
21    public int longestCommonSubsequence(String text1, String text2) {
22        int n = text1.length(), m = text2.length();
23
24        mem = new int[n+1][m+1];
25
26        for(int i=0; i<=n; i++){
27            mem[i][0] = 0;
28        }
29        for(int i=0; i<=m; i++){
30            mem[0][i] = 0;
31        }
32
33        for(int i=1; i<=n; i++){
34            for(int j=1; j<=m; j++){
35                int res=0;
36
37                if(text1.charAt(i-1) == text2.charAt(j-1)){
38                    res = 1 + mem[i-1][j-1];
39                }
40                else{
41                    res = Math.max(mem[i-1][j], mem[i][j-1]);
42                }
43
44                mem[i][j] = res;
45            }
46        }
47
48        return mem[n][m];
49    }
50}