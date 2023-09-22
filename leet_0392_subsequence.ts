function isSubsequence(s: string, t: string): boolean {

    if (s === '')
        return true
    let [ ls, lt ]= [ s.length, t.length ]
    let [ i, j ]= [ 0, 0 ]
    while (i < ls && j < lt) {
        if (s[i] === t[j]) {
            ++i
        }
        ++j
        if (i === ls)
            return true
    }
    return false
};
