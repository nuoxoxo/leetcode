var maxDepth = function(node) {
    if (!node)
        return 0
    let res = 0
    let dq = []
    dq.push(node)
    while (dq.length) {
        let len = dq.length
        while (len--) {
            let p = dq.shift()
            for (let c of p.children)
                if (c)
                    dq.push(c)
        }
        ++res
    }
    return res
};

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


