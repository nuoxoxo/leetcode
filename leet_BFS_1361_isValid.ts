function validateBinaryTreeNodes(n: number, leftChild: number[], rightChild: number[]): boolean {
    if (n === 1)
        return leftChild.length === 1 && leftChild[0] === -1
            && rightChild.length === 1 && rightChild[0] === -1
        // True if having only 2 children AND no grandchildren
    let R: number [] = []
    let Lset: Set<number> = new Set(leftChild)
    let Rset: Set<number> = new Set(rightChild)
    let node: number = -1
    while (++node < n) {
        if ( !Lset.has(node) && !Rset.has(node) && (leftChild[node] > -1 || rightChild[node] > -1))
            R.push(node)
    }
    if (R.length != 1) {
        return false
    }
    let root: number = R[0]
    let dq: number [] = [root]
    let seen: Set<number> = new Set()
    while (dq.length) {
        let size: number = dq.length
        let i: number = -1
        while (++i < size) {
            node = dq.shift()
            if (node === -1)
                continue
            if (seen.has(node))
                return false
            seen.add(node)
            dq.push(leftChild[node])
            dq.push(rightChild[node])
        }
    }
    return seen.size === n
};
