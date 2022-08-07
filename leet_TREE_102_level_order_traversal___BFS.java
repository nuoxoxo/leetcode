
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root)
    {
        List<List<Integer>>     res;
        Queue<TreeNode>         deq;
        // Deque<TreeNode>  deq; // deque also works

        if (root == null)
        {
            return new LinkedList<>();
        }
        deq = new LinkedList<>();
        res = new LinkedList<>();
        deq.add(root);
        while (!deq.isEmpty())
        {
            List<Integer>   temp;
            TreeNode        node;
            int             size;

            temp = new LinkedList<>();
            size = deq.size();
            while (size-- > 0)
            {
                node = deq.poll();
                if (node.left != null)
                {
                    deq.add(node.left);
                }
                if (node.right != null)
                {
                    deq.add(node.right);
                }
                temp.add(node.val);
            }
            res.add(temp);
        }
        return res;
    }
}

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
