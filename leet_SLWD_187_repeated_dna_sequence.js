/**
 * @param {string} s
 * @return {string[]}
 */

var findRepeatedDnaSequences = function(s) {
    n = s.length
    if (n < 10) return []
    seen = new Set()
    rest = new Set()
    i = -1
    while (++i < n - 9) {
        temp = s.substring(i, i + 10)
        if (seen.has(temp))
            rest.add(temp)
        seen.add(temp)
    }
    return [...rest]
};
