class Solution {
    public String longestCommonPrefix(String[] strs) {
        String result = strs[0];

        for(int i=1; i<strs.length; i++){
            while(!strs[i].startsWith(result)){
                result = result.substring(0, result.length()-1);

                if(result == "") return "";
            }
        }

        return result;
    }
}