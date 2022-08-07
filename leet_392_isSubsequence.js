var isSubsequence = function(s, t) {
    let len = s.length

    if (len == 0)
        return true
    if (t.length == 0)
        return false

    let i = 0
    for (let c of t){
        if (c == s[i])
            i++
        if (i == len)
            return true
    }
    return false
};
