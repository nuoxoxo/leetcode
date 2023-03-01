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
var invertTree = function(root) {
    if (!root)
        return root
    let D = [root]
    while (D.length != 0) {
        let node = D.shift()
        let temp = node.left
        node.left = node.right
        node.right = temp
        if (node.left)
            D.push(node.left)
        if (node.right)
            D.push(node.right)
    }
    return root
};
