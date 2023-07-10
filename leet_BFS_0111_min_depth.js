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
 * @return {number}
 */

var minDepth = function(root) {
    if (!root)
        return (0)

    let E = [ root ]
    let depth = 1
    while (E.length != 0) {
        let s = E.length
        let i = -1
        while (++i < s) {
            let node = E.shift()
            if (!node.left && !node.right) {
                return (depth)
            }
            if (node.left)
                E.push(node.left)
            if (node.right)
                E.push(node.right)
        }
        ++ depth
    }
    return (depth)
};
