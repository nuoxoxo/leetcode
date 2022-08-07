/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number[]}
 */

var postorder = function(root) {
    let v = []
    helper(root, v)
    return v
};

function helper(p, v) {
    if (p == null)
	    return
    for (let i of p.children)
        helper(i, v)
    v.push(p.val)
}
