/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var diagonalSort = function(mat) {
    let r = mat.length
    let c = mat[0].length
    let res = [...Array(r)].map(e => Array(c))
    // console.log(res)
    let i, j, d, t
    d = -1 * c
    while (++d < r) {
        let temp = []
        i = -1
        while (++i < r) {
            j = i - d
            if (j > -1 && j < c)
                temp.push(mat[i][j])
        }
        temp.sort((a, b) => a - b)
        i = -1
        t = 0
        while (++i < r) {
            j = i - d
            if (j > -1 && j < c)
                res[i][j] = temp[t++]
        }
    }
    return res
};
