/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    let m = [...Array(n)].map(e => Array(n).fill(0))
    let c, k, i, j, d
    i = j = d = 0
    k = n * n + 1   /// limit
    c = 1           /// count
    while (true) {
        while (j < n - d) {
            m[i][j] = c++
            j++
        }
        if (c == k)
            break
        i++
        j--
        while (i < n - d) {
            m[i][j] = c++
            i++
        }
        if (c == k)
            break
        i--
        j--
        while (j > d - 1) {
            m[i][j] = c++
            j--
        }
        if (c == k)
            break
        i--
        j++
        d++
        while (i > d - 1) {
            m[i][j] = c++
            i--
        }
        if (c == k)
            break
        i++
        j++
    }
    return m
};
