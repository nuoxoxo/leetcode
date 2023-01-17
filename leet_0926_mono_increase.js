/**
 * @param {string} s
 * @return {number}
 */
var minFlipsMonoIncr = function(s) {
    let z = 0
    let o = 0
    for (let c of s) {
        if (c == '1') {
            o++
        } else {
            z++
        }
        z = z < o ? z : o
    }
    return z
};
