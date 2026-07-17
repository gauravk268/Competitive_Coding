class Solution {
    public int maxVowels(String s, int k) {
        int n = s.length();
        int res = 0, temp = 0;

        for (int i = 0; i < n; i++) {
            if (i < k) {
                if (isVowel(s.charAt(i))) {
                    temp++;
                }
            } else {
                res = Math.max(res, temp);
                if (isVowel(s.charAt(i))) {
                    temp++;
                }
                if (isVowel(s.charAt(i - k))) {
                    temp--;
                }
            }
        }

        res = Math.max(res, temp);

        return res;
    }

    private boolean isVowel(char c) {
        return "aeiou".indexOf(c) != -1;
    }
}