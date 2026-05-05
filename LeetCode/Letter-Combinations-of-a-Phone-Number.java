1class Solution {
2    public static final Map<Character, String> mob = Map.of(
3            '2', "abc",
4            '3', "def",
5            '4', "ghi",
6            '5', "jkl",
7            '6', "mno",
8            '7', "pqrs",
9            '8', "tuv",
10            '9', "wxyz");
11    public int digitLen;
12    List<String> resp;
13
14    public List<String> letterCombinations(String digits) {
15        digitLen = digits.length();
16        resp = new ArrayList<>();
17
18        helper(digits, 0, new StringBuilder());
19        return resp;
20    }
21
22    private void helper(String digits, int i, StringBuilder res) {
23        if (i >= digitLen) {
24            resp.add(res.toString());
25            return;
26        }
27
28        for (char c : Solution.mob.get(digits.charAt(i)).toCharArray()) {
29            helper(digits, i + 1, res.append(c));
30            res.setLength(res.length() - 1);
31        }
32    }
33}
34