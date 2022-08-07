var diagonalSum = function(mat) {
    let r = mat.length
    if (!r) return mat[0][0]
    let res = 0, i = -1, j
    while (++i < r){
        j = -1
        while (++j < r)
            if (j == r - i - 1 || j == i)
                res += mat[i][j]
    }
    return res
};
