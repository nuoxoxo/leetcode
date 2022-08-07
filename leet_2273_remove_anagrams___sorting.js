/**
 * @param {string[]} words
 * @return {string[]}
 */

var removeAnagrams = function(words) {
    let res = [words[0]]
    let i = 0
    let len = words.length
    while (++i < len) {
        let L = words[i - 1].split('').sort().join('')
        let R = words[i].split('').sort().join('')

        while (L == R) {
            ++i
            if (i > len - 1)
                break
            R = words[i].split('').sort().join('')
        }
        if (i > len - 1)
            break
        res.push(words[i])
    }
    return res
};
