class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();

        int n=word1.length(), m=word2.length();
        int i=0, j=0;
        while(i<n && j<m){
            sb.append(word1.charAt(i++));
            sb.append(word2.charAt(j++));
        }

        while(i<n){
            sb.append(word1.charAt(i++));
        }

        while(j<m){
            sb.append(word2.charAt(j++));
        }

        return sb.toString();
    }
}