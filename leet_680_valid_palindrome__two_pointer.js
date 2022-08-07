/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
    n = s.length
    j = n - 1
    i = 0
    while (i < j) {
        if (s[i] != s[j]) {
            L = s.substring(i + 1, j + 1)
            R = s.substring(i, j)
            return L == L.split('').reverse().join('') ||
                R == R.split('').reverse().join('')
        }
        ++i
        --j
    }
    return true
};
