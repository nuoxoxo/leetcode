/**
 * @param {number[]} chalk
 * @param {number} k
 * @return {number}
 */

var chalkReplacer = function(chalk, k) {
    let len = chalk.length
    let i = 0
    let t = 0
    for (let c of chalk)
        t += c
    k %= t
    while (true) {
        if (k < chalk[i])
            return i
        k -= chalk[i]
        i = (i + 1) % len
    }
    return -1
};
