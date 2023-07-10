/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function(letters, target) {
    let n = letters.length
    let L = 0
    let R = n
    while (L < R) {
        let mid = Math.floor((R - L) / 2) + L
        if (letters[mid].charCodeAt(0) <= target.charCodeAt(0))
            L = mid + 1
        else
            R = mid
    }
    // if (R == n)
    //     return letters[0]
    // return letters[R]
	return letters[R % n]
};
