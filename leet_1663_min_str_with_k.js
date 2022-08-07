/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */

var getSmallestString = function(n, k) {
    let a = []
    let i
    i = -1
    while (++i < n) {
        -- k
        a.push('a')
    }
    i = n
    while (--i > -1) {
        if (k > 25) {
            k -= 25
            a[i] = 'z'
        } else {
            a[i] = String.fromCharCode(a[i].charCodeAt(0) + k)
            break
        }
    }
    return a.join('')
};
