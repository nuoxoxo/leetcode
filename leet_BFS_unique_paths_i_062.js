/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */

var uniquePaths = function(m, n) {
    let g = [...Array(m)].map(e => Array(n).fill(1))
    let dq = []
    dq.push([0, 0])
    while (dq.length != 0) {
        let p = dq.shift()
        let i = p[0]
        let j = p[1]
        if (i == m || j == n || g[i][j] > 1)
            continue
        if (i > 0 && j > 0)
            g[i][j] = g[i - 1][j] + g[i][j - 1]
        dq.push([i + 1, j])
        dq.push([i, j + 1])
    }
    return g[m - 1][n - 1]
};
