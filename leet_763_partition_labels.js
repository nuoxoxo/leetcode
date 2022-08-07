/**
 * @param {string} s
 * @return {number[]}
 */

var partitionLabels = function(s) {
    let last_index = new Object()
    let len = s.length
    let res = []
    let i, j

    i = -1
    while (++i < len) {
        last_index[s[i]] = i
    }
    i = 0
    while (i < len) {
        let last = last_index[s[i]]
        if (last == len - 1) {
            res.push(len - i)
            return res
        }
        j = i - 1
        while (++j < last) {
            last = last_index[s[j]] > last ? last_index[s[j]] : last
        }
        res.push(1 + j - i)
        i = j + 1
    }
    return res 
};
