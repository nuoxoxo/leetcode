function kthSmallest(matrix: number[][], k: number): number {
    let g = []
    let i = -1
    let side = matrix.length
    while (++i < side) {
        let j = -1
        while (++j < side)
            g.push(matrix[i][j])
    }
    g.sort((a, b) => a - b);
    return g[k - 1]
};
