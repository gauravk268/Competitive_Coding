1class Solution {
2    private boolean isVow(char a) {
3        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
4    }
5
6    public int maxVowels(String s, int k) {
7        int n = s.length(), sum = 0;
8
9        for (int i = 0; i < k; i++) {
10            if (isVow(s.charAt(i)))
11                sum++;
12        }
13
14        int tempSum = sum;
15        for (int i = k; i < n; i++) {
16            if (isVow(s.charAt(i)))
17                tempSum++;
18            if (isVow(s.charAt(i - k)))
19                tempSum--;
20            sum = Math.max(sum, tempSum);
21        }
22
23        return sum;
24    }
25}