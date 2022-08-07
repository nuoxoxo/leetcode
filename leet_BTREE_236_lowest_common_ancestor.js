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
var lowestCommonAncestor = function(node, p, q) {
    if (node == null || node == p || node == q)
        return node
    let L = lowestCommonAncestor(node.left, p, q)
    let R = lowestCommonAncestor(node.right, p, q)
    if (!L)
        return R
    if (!R)
        return L
    return node
};
