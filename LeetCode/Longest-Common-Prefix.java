class Solution {
    public String longestCommonPrefix(String[] strs) {
        String result = strs[0];
        for(int i=1; i<strs.length; i++){
            StringBuffer tempStr = new StringBuffer();

            for(int j=0; j<result.length(); j++){
                if(j<strs[i].length() && strs[i].charAt(j) == result.charAt(j)){
                    tempStr.append(result.charAt(j));
                }
                else{
                    break;
                }
            }

            result = tempStr.toString();
        }

        return result;
    }
}