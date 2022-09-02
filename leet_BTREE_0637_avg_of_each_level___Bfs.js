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
 * @return {number[]}
 */
var averageOfLevels = function(root) {
    let r = []
    let dq = [root]
    while (dq.length != 0) {
        let len = dq.length
        let tmp = 0
        let i = -1
        while (++i < len) {
            let node = dq.shift()
            tmp += node.val
            if (node.left)
                dq.push(node.left)
            if (node.right)
                dq.push(node.right)
        }
        r.push(tmp / len)
    }
    return r
};
