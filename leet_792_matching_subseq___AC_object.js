/**
 * @param {string} s
 * @param {string[]} words
 * @return {number}
 */
var numMatchingSubseq = function(s, words) {
    let seen = new Object()
    let res = 0
    for (let w of words) {
        if (seen.hasOwnProperty(w))
            seen[w] += 1
        else
            seen[w] = 1
    }
    let copy = [...new Set(words)]
    // console.log(seen, '\n', words, '\n', copy)
    let ls = s.length
    for (let w of copy) {
        let lw = w.length
        let i = 0
        let j = 0
        while (i < ls && j < lw) {
            if (s[i] == w[j])
                j++
            i++
        }
        if (j == lw)
            res += seen[w]
    }
    return res
};
