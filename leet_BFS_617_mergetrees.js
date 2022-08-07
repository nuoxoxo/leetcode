/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {TreeNode}
 */

var mergeTrees = function(r1, r2) {
    if (!r1)
        return (r2)
    if (!r2)
        return (r1)
    let d1 = [r1]
    let d2 = [r2]
    while (d2.length != 0) {
        let p1 = d1.shift()
        let p2 = d2.shift()
        p1.val += p2.val
        if (p2.left) {
            if (p1.left) {
                d1.push(p1.left)
                d2.push(p2.left)
            } else {
                p1.left = p2.left
            }
        }
        if (p2.right) {
            if (p1.right) {
                d1.push(p1.right)
                d2.push(p2.right)
            } else {
                p1.right = p2.right
            }
        }
    }
    return (r1)
};
