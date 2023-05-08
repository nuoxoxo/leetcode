function diagonalSum(mat: number[][]): number {
    let i = -1, j
    let res = 0
    let len: number = mat.length
    while (++i < len) {
        console.log(mat[i][i], mat[i][len - i - 1])
        res += mat[i][i] + mat[i][len - i - 1]

        // way 1

        /*
        if (i == len - i - 1) {
            res -= mat[i][i]
        }
        */
    }

    // way 2

    if (len % 2) {
        let mid = Math.floor(len / 2)
        res -= mat[mid][mid]
    }

    return res
};
