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
17    private TreeNode getNextNode(TreeNode root) {
18        root = root.right;
19        while (root != null && root.left != null) {
20            root = root.left;
21        }
22        return root;
23    }
24
25    public TreeNode deleteNode(TreeNode root, int key) {
26        if (root == null) {
27            return root;
28        }
29
30        if (key > root.val) {
31            root.right = deleteNode(root.right, key);
32        } else if (key < root.val) {
33            root.left = deleteNode(root.left, key);
34        } else {
35            if (root.left == null)
36                return root.right;
37            if (root.right == null)
38                return root.left;
39
40            TreeNode repl = getNextNode(root);
41            root.val = repl.val;
42            root.right = deleteNode(root.right, repl.val);
43        }
44
45        return root;
46    }
47}