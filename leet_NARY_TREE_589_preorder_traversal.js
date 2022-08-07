/**
 * // Definition for a Node.
 * function Node(val, children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number[]}
 */
var preorder = function(root) {
    let v = []
    helper(root, v)
    return v
};

function helper(p, v) {
    if (p == null)
	return
    v.push(p.val)
    for (let i of p.children)
        helper(i, v)
}


