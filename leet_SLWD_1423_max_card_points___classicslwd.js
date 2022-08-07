/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
var maxScore = function(p, k) {
    // console.log(p.slice(k))
    let best = p.slice(0, k).reduce((a, b) => a + b, 0)
    let temp = best
    let n = p.length
    let i = 0
    while (++i < k + 1) {
        temp += p[n - i]
        temp -= p[k - i]
        best = best > temp ? best : temp
    }
    return best
};
