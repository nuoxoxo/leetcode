/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */

var hasAllCodes = function(s, k) {
    n = s.length
    if (k > n)
        return false
    st = new Set()
    i = -1
    while (++i < n - k + 1)
        st.add(s.substring(i, i + k))
    if (st.size == Math.pow(2, k))
        return true
    return false
};
