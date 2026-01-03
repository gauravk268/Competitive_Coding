1class Solution {
2    public int compress(char[] chars) {
3        int n = chars.length;
4        if (n == 1)
5            return 1;
6
7        int count = 1;
8        StringBuilder sb = new StringBuilder();
9        for (int i = 1; i < n; i++) {
10            if (chars[i] == chars[i - 1]) {
11                count++;
12            } else {
13                sb.append(chars[i - 1]);
14                if (count != 1) {
15                    sb.append(Integer.toString(count));
16                }
17                count = 1;
18            }
19        }
20
21        sb.append(chars[n - 1]);
22        if (count != 1) {
23            sb.append(Integer.toString(count));
24        }
25
26        System.out.printf("%s", sb.toString());
27        for (int i = 0; i < sb.toString().length(); i++) {
28            chars[i] = sb.charAt(i);
29        }
30
31        return sb.length();
32    }
33}