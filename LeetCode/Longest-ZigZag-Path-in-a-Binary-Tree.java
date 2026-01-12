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
17    private int result;
18
19    private void helper(TreeNode root, int len, int dir) {
20        if (root == null)
21            return;
22
23        this.result = Math.max(this.result, len);
24
25        if (dir == 1) {
26            helper(root.right, len + 1, -1);
27            helper(root.left, 1, 1);
28        } else {
29            helper(root.left, len + 1, 1);
30            helper(root.right, 1, -1);
31        }
32
33    }
34
35    public int longestZigZag(TreeNode root) {
36        this.result = 0;
37
38        helper(root.left, 1, 1);
39        helper(root.right, 1, -1);
40
41        return this.result;
42    }
43}