class Solution {
    public String reverseWords(String s) {
        String[] words = s.split(" ");

        StringBuffer str = new StringBuffer();
        
        for(int i=words.length-1; i>=0; i--){
            if(words[i] != ""){
                str.append(words[i]);
                str.append(" ");
            }
        }

        return str.toString().trim();
    }   
}