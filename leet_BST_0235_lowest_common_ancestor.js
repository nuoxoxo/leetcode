/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
        here = root.val
        pv = p.val
        qv = q.val
        if (here > pv && here > qv)
            return lowestCommonAncestor(root.left, p, q)
        if (here < pv && here < qv)
            return lowestCommonAncestor(root.right, p, q)
        return root
};
