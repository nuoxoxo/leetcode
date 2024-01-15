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

function maxAncestorDiff(root: TreeNode | null): number {

    const solutions: ((node: TreeNode | null, L:number, R:number) => number)[] = [
        BFS, DFS
    ]
    const methods: string[] = [ 'BFS', 'DFS' ]
    let n = Math.floor(Math.random() * solutions.length)
    console.log( methods[n] )
    return solutions[n](root, root.val, root.val)
};

// BFS
const BFS = (node: TreeNode | null, L: number, R: number): number => {

    const queue: [TreeNode | null, number, number][] = [[node, L, R]]
    let res = 0

    while (queue.length > 0) {
        const [currentNode, currentL, currentR] = queue.shift() || [null, 0, 0]
        if (currentNode) {
            L = Math.min(currentL, currentNode.val)
            R = Math.max(currentR, currentNode.val)
            if (currentNode.left)
                queue.push([currentNode.left, L, R])
            if (currentNode.right)
                queue.push([currentNode.right, L, R]);
            res = Math.max(res, R - L);
        }
    }
    return res;
}

// DFS
const DFS = (node: TreeNode | null, L: number, R: number): number => {

    if (node === null || node == undefined)
        return R - L
    L = Math.min(L, node.val)
    R = Math.max(R, node.val)
    return Math.max(
        DFS(node.left, L, R),
        DFS(node.right, L, R)
    )
}
