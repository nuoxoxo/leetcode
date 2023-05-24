/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number}
 */
var maxDepth = function(root) {
    let res = 0
    if (!root)  return res
    for (let n of root.children) {
        res = Math.max(maxDepth(n), res)
    }
    return 1 + res
};
