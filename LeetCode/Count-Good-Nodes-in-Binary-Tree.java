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
17    private int count(TreeNode root, int maxVal) {
18        if (root == null)
19            return 0;
20
21        int result = 0;
22        if (root.val >= maxVal) {
23            result++;
24            maxVal = root.val;
25        }
26        if (root.left != null)
27            result += count(root.left, maxVal);
28        if (root.right != null)
29            result += count(root.right, maxVal);
30
31        return result;
32    }
33
34    public int goodNodes(TreeNode root) {
35        return count(root, Integer.MIN_VALUE);
36    }
37}