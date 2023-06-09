/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function(letters, target) {
    n = letters.length
    i = 0
    j = n
    while (i < j) {
        mid = Math.floor((j - i) / 2) + i
        if (letters[mid].charCodeAt(0) <= target.charCodeAt(0))
            i = mid + 1
        else
            j = mid
    }
    if (n == j)
        return letters[0]
    return letters[j]
};
