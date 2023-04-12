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
    let qo = [], qc = []
    qo.push(o)
    qc.push(c)
    while (qo.length != 0) {
        o = qo.shift()
        c = qc.shift()
        if (o == t)
            return c
        if (o.left)
            qo.push(o.left)
        if (o.right)
            qo.push(o.right)
        if (c.left)
            qc.push(c.left)
        if (c.right)
            qc.push(c.right)
    }
    return null
};
