/**
 * @param {string} s
 * @return {string}
 */

var removeDuplicateLetters = function(s) {
    let visited = new Array(26)
    let counter = new Array(26)
    visited.fill(false)
    counter.fill(0)
    let len = s.length
    let res = ""
    let i = -1
    while (++i < len) {
        ++counter[ s.charCodeAt(i) - 97 ]
    }
    i = -1
    while (++i < len) {
        n = s.charCodeAt(i)
        if (visited[n - 97]) {
            --counter[n - 97]
        } else {
            
            while (res != "" && res.charCodeAt(res.length - 1) >= n &&
                   counter[res.charCodeAt(res.length - 1) - 97] > 1) {
                let last = res.length - 1
                counter[res.charCodeAt(last) - 97]--
                visited[res.charCodeAt(last) - 97] = false
                res = res.slice(0, -1)
            }
            res += s[i]
            visited[n - 97] = true
        }
    }
    return res
}
