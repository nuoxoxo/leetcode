/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} original
 * @param {TreeNode} cloned
 * @param {TreeNode} target
 * @return {TreeNode}
 */

var getTargetCopy = function(o, c, t){
    if (!o)
        return null
    if (o == t)
        return c
    dq = []
    dq.push(c)
    while (dq.length != 0) {
        c = dq.shift()
        if (c.val == t.val)
            return c
        if (c.left)
            dq.push(c.left)
        if (c.right)
            dq.push(c.right)
    }
    return null
};
