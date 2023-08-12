/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */

var uniquePathsWithObstacles = function(G) {
    let c = G[0].length
    let r = G.length
    let g = [...Array(r)].map(e => Array(c).fill(0))
    let dr = [[1, 0], [0, 1]]
    let dq = []
    g[0][0] = G[0][0] == 0 ? 1 : 0
    dq.push([0, 0])
    while (dq.length != 0) {
        let p = dq.shift()
        let i = p[0]
        let j = p[1]
        let v = g[i][j]
        for (let d of dr) {
            let di = d[0] + i
            let dj = d[1] + j
            // console.log(di, dj)
            if (di == r || dj == c || G[di][dj] == 1)
                continue
            if (g[di][dj] == 0)
                dq.push([di, dj])
            g[di][dj] += v
        }
    }
    return g[r - 1][c - 1]
};
