/**
 * @param {number[]} nums
 * @return {boolean}
 */

var checkPossibility = function(n)
{
    let moveup = 0
    let i = 0
    while (++i < n.length) {
        if (n[i - 1] <= n[i])
            continue
        if (moveup == 1)
            return false
        if (i > 1) {
            if (n[i - 2] == n[i - 1] || n[i - 2] > n[i])
                n[i] = n[i - 1]
            else
                n[i - 1] = n[i - 2]
        }
        moveup++
    }
    return true
};
