1class Solution {
2
3    public List<String> letterCombinations(String digits) {
4        List<String> mob = List.of("abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz");
5
6        List<String> resp = new ArrayList<>();
7        helper(resp, mob, digits, 0, "");
8        return resp;
9    }
10
11    private void helper(List<String> resp, List<String> mob, String digits, int i, String res){
12        if(i >= digits.length()){
13            resp.add(res);
14            return;
15        }
16
17        String key = mob.get(digits.charAt(i)-'0'-2);
18        
19        for(char c:key.toCharArray()){
20            helper(resp, mob, digits, i+1, res + c);
21        }
22    }
23}