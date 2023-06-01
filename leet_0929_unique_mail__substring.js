/**
 * @param {string[]} emails
 * @return {number}
 */

var numUniqueEmails = function(emails) {
    let s = new Set()
    for (let m of emails) {
        let i = 0
        let n = m.length
        while (m[i] != '@')
            ++i
        s.add( make(m.substring(0, i)) + '@' + m.substring(i + 1, n - 1) )
    }
    return s.size
};

function make(o) {
    let s = ''
    let i = 0
    while (i < o.length && o[i] != '+') {
        if (o[i] != '.')
            s += o[i]
        ++i
    }
    return s
}
