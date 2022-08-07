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
    let head = root
    while (head){
        let dumm = new Node(0)
        let temp = dumm
        while (head){
            if (head.left){
                temp.next = head.left
                temp = temp.next
            }
            if (head.right){
                temp.next = head.right
                temp = temp.next
            }
            head = head.next
        }
        head = dumm.next
    }
    return root
};
