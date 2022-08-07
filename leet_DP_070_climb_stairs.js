/**
 * @param {number} n
 * @return {number}
 */

var climbStairs = function(n) {
    if (n < 3)
        return n
    let dict = new Object()
    let i = 1
    dict[0] = 1
    dict[1] = 1
    dict[2] = 2
    while (++ i < n + 1)
        dict[i] = dict[i - 1] + dict[i - 2]
    return dict[n]
};
