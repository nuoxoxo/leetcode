var lengthOfLongestSubstring = function(s) {
    let len = s.length
    if (len == 0 || len == 1)
        return len
    let res = 0
    let i = -1
    while (++i < len) {
        let E = new Set()
        let j = i - 1
        while (++j < len) {
            let c = s[ j ]
            if (!E.has(c))
                E.add(c)
            else
                break
        }
        let es = E.size
        res = res < es ? es : res
    }
    return res 
};

/**
 * @param {string} s
 * @return {number}
 */

