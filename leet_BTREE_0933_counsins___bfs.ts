/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function isCousins(root: TreeNode | null, x: number, y: number): boolean {
    // let all_level = [] // way 1 sacrifies space complexity
    let d = [root]
    while (d.length) {
        let i = -1
        let len = d.length
        let curr = []
        while (++i < len) {
            let node = d.shift()
            curr.push(node.val)
            if ((node.left && node.right) &&
                ((node.left.val === x && node.right.val === y) ||
                (node.left.val === y && node.right.val === x))
            ) {
                return false
            } 
            if (node.left) {
                d.push(node.left)
            }
            if (node.right) {
                d.push(node.right)
            }
            if (curr.includes(x) && curr.includes(y)) {
                return true
            }
        }
        // console.log(curr_level)
        // all_level.push(curr_level)
    }
    // you don't have traverse it again
    /*
    for (let lv of all_level) {
        console.log(lv)
        if (lv.includes(x) && lv.includes(y)) {
            return true
        }
    }
    */
    return false
};
