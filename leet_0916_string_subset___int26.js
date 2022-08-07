/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {string[]}
 */
var wordSubsets = function(words1, words2) {
    res = []
    n1 = words1.length
    n2 = words2.length
    a = 'a'.charCodeAt(0)
    freq = new Array(26).fill(0)
    for (let s of words2) {
        temp = new Array(26).fill(0)
        for (let c of s) {
            asc = c.charCodeAt(0) - a
            temp[asc] ++
            freq[asc] = Math.max(freq[asc], temp[asc])
        }
    }
    for (let s of words1) {
        temp = new Array(26).fill(0)
        for (let c of s) {
            temp[c.charCodeAt(0) - a] ++
        }
        i = -1
        while (++i < 26 && temp[i] >= freq[i])
            ;
        if (i == 26)
            res.push(s)
    }
    return res
};
