/**
 * @param {number[][]} grid
 * @return {number}
 */

var shortestPathBinaryMatrix = function(g) {
    n = g.length
    if (n < 2)
        return 1
    if (g[0][0] || g[n - 1][n - 1])
        return -1
    di = [-1,-1,-1, 0,0, 1,1,1]
    dj = [-1, 0, 1,-1,1,-1,0,1]
    dq = [[0, 0]]
    g[0][0] = 1
    count = 0
    while (true) {
        len = dq.length
        if (!len)
            break
        ++count
        while (len--) {
            p = dq.shift()
            i = p[0]
            j = p[1]
            if (i == n - 1 && j == n - 1) { // ie. arrived!
                return count
            }
            k = -1
            while (++k < 8) {
                x = i + di[k]
                y = j + dj[k]
                if (x > -1 && y > -1 && x < n && y < n && g[x][y] == 0) {
                    dq.push([x, y])
                    g[x][y] = 1
                }
            }
        }
    }
    return -1
};
