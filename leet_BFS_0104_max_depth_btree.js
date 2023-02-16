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
var maxDepth = function(root) {
    if (root == null)
        return 0
    let arr = [root]
    let res = 0;
    while (arr.length !== 0) {
        let len = arr.length
        while (--len > -1) {
            let node = arr.shift()
            if (node.left)
                arr.push(node.left)
            if (node.right)
                arr.push(node.right)
        }
        ++res;
    }
    return res;
};
