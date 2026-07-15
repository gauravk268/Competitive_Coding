class Solution {
    public boolean isSubsequence(String s, String t) {
        int j = 0, n = s.length();

        if(n==0)    return true;

        for (int i = 0; i < t.length(); i++) {
            if (s.charAt(j) == t.charAt(i)) {
                j++;
                if (j == n)
                    return true;
            }
        }

        return false;
    }
}