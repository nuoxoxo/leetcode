/**
 * @param {string[]} words
 * @return {number}
 */

var maxProduct = function(words) {
    let n = words.length, res = 0, i = -1, j
    let count = [...Array(n)].map(e => Array(26).fill(0))

    while (++i < n) {
        for (let c of words[i])
            ++count[i][c.charCodeAt(0) - 'a'.charCodeAt(0)]
        j = -1
        while (++j < i)
            if (cmp(count[i], count[j]))
                res = Math.max(res, words[i].length * words[j].length)
    }
    return res
};

var cmp = function(a, b) {
    let i = -1;
    while (++i < 26)
        if  (a[i] > 0 && b[i] > 0)
            return false;
    return true
}
