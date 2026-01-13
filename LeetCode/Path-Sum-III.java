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
17    private int count(TreeNode root, long tgtSum) {
18        if (root == null) {
19            return 0;
20        }
21
22        int result = 0;
23        if (root.val == tgtSum) {
24            result++;
25        }
26
27        result += count(root.left, tgtSum - root.val);
28        result += count(root.right, tgtSum - root.val);
29
30        return result;
31    }
32
33    public int pathSum(TreeNode root, int targetSum) {
34        if (root == null)
35            return 0;
36
37        int result = 0;
38        result = count(root, targetSum);
39
40        result += pathSum(root.left, targetSum);
41        result += pathSum(root.right, targetSum);
42
43        return result;
44    }
45}