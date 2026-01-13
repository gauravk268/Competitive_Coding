1/**
2 * Definition for a binary tree node.
3 * public class TreeNode {
4 *     int val;
5 *     TreeNode left;
6 *     TreeNode right;
7 *     TreeNode(int x) { val = x; }
8 * }
9 */
10class Solution {
11    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
12        if (root == null || root == p || root == q) {
13            return root;
14        }
15
16        TreeNode left = lowestCommonAncestor(root.left, p, q);
17        TreeNode right = lowestCommonAncestor(root.right, p, q);
18
19        if (left != null && right != null) {
20            return root;
21        }
22
23        return (left != null) ? left : right;
24    }
25}