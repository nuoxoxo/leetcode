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

var convertBST = function(root) {
    let total = 0
    function reverse_inorder_traversal(node) {
        if (node) {
            reverse_inorder_traversal(node.right)
            total += node.val
            node.val = total
            reverse_inorder_traversal(node.left)
        }
        return node
    }
    return reverse_inorder_traversal(root)
};

function reverse_inorder_traversal(node, total) {
    if (node) {
        reverse_inorder_traversal(node.right, total)
        total += node.val
        node.val = total
        reverse_inorder_traversal(node.left, total)
    }
    return node
};
