class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();
        String[] holder = s.split(" ");

        for (int i = holder.length - 1; i >= 0; i--) {
            if(!holder[i].trim().isEmpty()){
                sb.append(holder[i]);
                sb.append(" ");
            }
        }

        return sb.toString().trim();
    }
}