/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(node) {
    if (!node)
        return node
    Q = []
    Q.push(node)
    while (Q.length != 0) {
        n = Q.shift()
        tmp = n.left
        n.left = n.right
        n.right = tmp
        if (n.left)
            Q.push(n.left)
        if (n.right)
            Q.push(n.right)
    }
    return node
};
