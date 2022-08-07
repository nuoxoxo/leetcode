var areAlmostEqual = function(s1, s2) {
    if (s1 == s2)
        return true
    let len = s1.length
    let tmp1 = "", tmp2 = ""
    let i = -1, n = 0
    while (++i < len){
        if (s1[i] != s2[i]){
            tmp1 += s1[i]
            tmp2 += s2[i]
            n++
        }
        if (n > 2)
            return false
    }
    if (n ^ 2)
        return false
    tmp1 = tmp1.split("").sort().join("")
    tmp2 = tmp2.split("").sort().join("")
    if (tmp1 == tmp2)
        return true
    return false
};
