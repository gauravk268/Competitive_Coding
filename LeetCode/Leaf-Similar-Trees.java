1/**
2 * Definition for a binary tree node.
3 * public class TreeNode {
4 *     int val;
5 *     TreeNode left;
6 *     TreeNode right;
7 *     TreeNode() {}
8 *     TreeNode(int val) { this.val = val; }
9 *     TreeNode(int val, TreeNode left, TreeNode right) {
10 *         this.val = val;
11 *         this.left = left;
12 *         this.right = right;
13 *     }
14 * }
15 */
16class Solution {
17    private List<Integer> dfs(TreeNode root) {
18        if (root == null)
19            return null;
20
21        if (root.left == null && root.right == null) {
22            return List.of(root.val);
23        }
24
25        List<Integer> result = new ArrayList<>();
26        if(root.left != null)
27            result.addAll(dfs(root.left));
28            
29        if(root.right != null)
30            result.addAll(dfs(root.right));
31
32        return result;
33    }
34
35    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
36        List<Integer> first = dfs(root1), second = dfs(root2);
37
38        return first.equals(second);
39    }
40}