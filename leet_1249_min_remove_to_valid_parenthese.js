/**
 * @param {string} s
 * @return {string}
 */
var minRemoveToMakeValid = function(s) {
    let a = Array.from(s)
    let d = []
    let i = -1
    while (++i < s.length) {
        if (s[i] == '(')
            d.push(i)
        if (s[i] == ')') {
            if (d.length != 0)
                d.pop()
            else
                a[i] = ''
        }
    }
    while (d.length != 0)
        a[ d.shift() ] = ''
    return a.join('')
};
