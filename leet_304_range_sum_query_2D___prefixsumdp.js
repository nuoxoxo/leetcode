/**
 * @param {number[][]} matrix
 */

var NumMatrix = function(m) {
    let r = m.length
    let c = m[0].length
    this.g = [...Array(1 + r)].map(e => Array(1 + c).fill(0))
    let i = -1, j
    while (++i < r) {
        j = -1
        while (++j < c) {
            let U = this.g[i][1 + j]
            let L = this.g[1 + i][j]
            let LU = this.g[i][j]
            this.g[1 + i][1 + j] = m[i][j] + U + L - LU
        }
    }
};

/** 
 * @param {number} row1 
 * @param {number} col1 
 * @param {number} row2 
 * @param {number} col2
 * @return {number}
 */

NumMatrix.prototype.sumRegion = function(r1, c1, r2, c2) {
    let self = this.g[r1][c1]
    let U = this.g[r1][c2 + 1]
    let L = this.g[r2 + 1][c1]
    let DR = this.g[1 + r2][1 + c2]
    return self + DR - U - L
};

/** 
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
