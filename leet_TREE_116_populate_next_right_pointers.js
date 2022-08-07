/**
 * // Definition for a Node.
 * function Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {Node} root
 * @return {Node}
 */

var connect = function(root) {
    if (!root)
        return root
    let node = root
    while (node.left) {
        let p = node
        while (p) {
            p.left.next = p.right
            if (p.next)
                p.right.next = p.next.left
            p = p.next
        }
        node = node.left
    }
    return root
};
