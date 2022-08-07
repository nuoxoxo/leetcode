/**
 * @param {number} n
 * @return {number}
 */
var tribonacci = function(n) {
    if (n == 0) return 0
    if (n < 3)  return 1
    let g = new Array(1 + n)
    g[0] = 0
    g[1] = g[2] = 1
    i = 3
    while (i < 1 + n) {
        g[i] = g[i - 3] + g[i - 2] + g[i++ - 1]
    }
    return g[n]
};
