function diagonalSum(mat: number[][]): number {
    let i = -1, j
    let res = 0
    while (++i < mat.length) {
        console.log(mat[i][i], mat[i][mat.length - i - 1])
        res += mat[i][i] + mat[i][mat.length - i - 1]
        if (i == mat.length - i - 1) {
            res -= mat[i][i]
        }
    }
    return res
};
