var increasingBST = function(root) {
    nodes = []
    inorder_traversal(root)
    i = -1
    while (++i < nodes.length - 1) {
        nodes[i].right = nodes[i + 1]
        nodes[i].left = null
    }
    nodes[i].right = null
    nodes[i].left = null
    return nodes[0]
};

function    inorder_traversal(node) {
    if (node) {
        inorder_traversal(node.left)
        nodes.push(node)
        inorder_traversal(node.right)
    }
}


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
