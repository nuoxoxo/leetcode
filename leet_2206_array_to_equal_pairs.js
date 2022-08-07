/**
 * @param {number[]} nums
 * @return {boolean}
 */
var divideArray = function(n) {
    n.sort()
    let i = 0, j = n.length - 1
    while (i < j) {
        if (n[i] != n[i + 1] || n[j] != n[j - 1])
            return false
        i += 2
        j -= 2
    }
    return true
};
