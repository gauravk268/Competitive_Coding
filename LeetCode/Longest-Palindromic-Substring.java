class Solution {
    public String longestPalindrome(String s) {
        if (isPalin(s) || s.length() <= 1)
            return s;

        String resp = Character.toString(s.charAt(0));

        for(int i=1; i<s.length(); i++){
            for(int j=0; j<=i; j++){
                int k = s.length()-i+j;
                if(isPalin(s.substring(j, k))){
                    return s.substring(j, k);
                }
            }
        }

        return resp;
    }

    public boolean isPalin(String s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
}