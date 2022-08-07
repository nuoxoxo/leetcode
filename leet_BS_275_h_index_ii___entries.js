/**
 * @param {number[]} citations
 * @return {number}
 */

var hIndex = function(citations) {
    let res = 0
    citations.sort((a, b) => b - a)
    for (let [i, n] of citations.entries()) {
        if (n > i) {
            res = i + 1
        } else {
            break
        }
    }
    return res
};
