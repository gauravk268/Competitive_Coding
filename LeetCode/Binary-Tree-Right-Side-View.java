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
17    public List<Integer> rightSideView(TreeNode root) {
18        Queue<TreeNode> q = new LinkedList<>();
19        List<Integer> result = new ArrayList<>();
20
21        if (root == null)
22            return result;
23
24        q.add(root);
25        while (!q.isEmpty()) {
26            int n = q.size();
27            TreeNode rightNode = null;
28
29            for (int i = 0; i < n; i++) {
30                TreeNode temp = q.poll();
31                rightNode = temp;
32
33                if (temp.left != null)
34                    q.add(temp.left);
35                if (temp.right != null)
36                    q.add(temp.right);
37            }
38
39            result.add(rightNode.val);
40        }
41
42        return result;
43    }
44}