/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number[][]}
 */

var levelOrder = function(root) {
    let r = []
    if (!root) {
        return r
    }
    r.push([root.val])
    let dq = [root]
    while (dq.length > 0) {
        let temp = []
        let len = dq.length
        while (len-- > 0) {
            let node = dq.shift()
            for (let n of node.children) {
                dq.push(n)
                temp.push(n.val)
            }
        }
        if (temp.length > 0) {
            r.push(temp)
        }
    }
    return r
};
