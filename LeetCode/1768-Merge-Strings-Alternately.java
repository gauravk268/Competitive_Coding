class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();

        int n=word1.length(), m=word2.length();
        int i=0;
        while(i<n && i<m){
            sb.append(word1.charAt(i));
            sb.append(word2.charAt(i++));
        }

        sb.append(word1.substring(i, n));
        sb.append(word2.substring(i, m));

        return sb.toString();
    }
}