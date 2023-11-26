function largestSubmatrix(matrix: number[][]): number {
    const R: number = matrix.length
    const C: number = matrix[0].length
    let r = 0, c
    while (++r < R) {
        c = -1
        while (++c < C) {
            if (matrix[r - 1][c] && matrix[r][c]) {
                matrix[r][c] += matrix[r - 1][c]
            }
        }
    }
    let res = 0
    for (const row of matrix) {
        row.sort((a, b) => b - a)
        c = -1
        while (++c < C) {
            res = Math.max(res, row[c] * (c + 1))
        }
    }

    return res
};
