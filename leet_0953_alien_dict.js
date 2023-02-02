/**
 * @param {string[]} words
 * @param {string} order
 * @return {boolean}
 */

var isAlienSorted = function(words, order) {
    let dict = new Object()
    let oz = order.length
    let wz = words.length
    let i = -1

    while (++i < oz) dict[ order[i] ] = i
    i = -1
    while (++i < wz - 1) {
        let L = words[i], R = words[i + 1]
        let Ls = L.length, Rs = R.length
        let j = -1
        while (++j < Ls) {
            if (Rs == j)    return false
            if (L[j] != R[j]) {
                if (dict[L[j]] > dict[R[j]] )   return false
                break
            }
        }
    }
    return true 
};
