class Solution {
    public String reverseVowels(String s) {
        int l = s.length();
        int i = 0, j = l - 1;

        StringBuilder sb = new StringBuilder(s);
        while (i < j) {
            while (i < l && !isVowel(s.charAt(i))) {
                i++;
            }

            while (j >= 0 && !isVowel(s.charAt(j))) {
                j--;
            }

            if (i < l && j >= 0) {
                sb.setCharAt(i, s.charAt(j));
                sb.setCharAt(j, s.charAt(i));
                i++;
                j--;
            }
        }

        return sb.toString();
    }

    private boolean isVowel(char c) {
        return ("AEIOUaeiou".indexOf(c) != -1);
    }
}