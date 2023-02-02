/**
 * @param {string[]} words
 * @param {string} order
 * @return {boolean}
 */

var isAlienSorted = function(words, order) {
    let dict = new Object()
    let i = -1

    while (++i < order.length)
        dict[ order[i] ] = i
    i = -1
    while (++i < words.length - 1) {
        let L = words[i], R = words[i + 1]
        let Lsize = L.length, Rsize = R.length
        let j = -1
        while (++j < Lsize) {
            if (j == Rsize)
                return false
            if (L[j] != R[j]) {
                if (dict[L[j]] > dict[R[j]])
                    return false
                break
            }
        }
    }
    return true 
};
