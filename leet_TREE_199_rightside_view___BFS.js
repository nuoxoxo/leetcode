var rightSideView = function(node) {
    res = []
    if (!node)
        return res
    dq = [node]
    while (dq.length != 0) {
        len = dq.length
        i = 0
        while (++i < len + 1) {
            node = dq.shift()
            if (i == len)
                res.push(node.val)
            if (node.left)
                dq.push(node.left)
            if (node.right)
                dq.push(node.right)
        }
    }
    return res
};


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

