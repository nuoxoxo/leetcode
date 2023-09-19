/**
 * @param {number[]} nums
 * @return {number}
 */

var findDuplicate = function(a) {
    a.sort()
    let n = a.length
    if (n == 2)
        return a[0]
    let i = 0
    let j = n - 1
    n = Math.floor(n / 2)
    while (++i != --j && i < n && j > n) {
        if (a[i] == a[i - 1])
            return a[i]
        if (a[j] == a[j + 1])
            return a[j]
    }
    return a[i]
};
