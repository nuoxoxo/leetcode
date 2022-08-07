/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(n, target) {
    r = n.length - 1
    if (r == 1)
        return [1, 2]
    i = 0
    while (i < r) {
        t = n[i] + n[r]
        if (t == target)
            break
        if (t < target)
            ++i
        else
            --r
    }
    return [i + 1, r + 1]
};
