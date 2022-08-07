/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */

var transpose = function(m) {
    let g = []
    let c = -1
    let r
    while (++c < m[0].length) {
        let temp = []
        r = -1
        while (++r < m.length)
            temp.push(m[r][c])
        g.push(temp)
    }
    return g
};
