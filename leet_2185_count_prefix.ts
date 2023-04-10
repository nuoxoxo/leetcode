function prefixCount(words: string[], pref: string): number {
    let res = 0
    for (let w of words) {
        res += helper(w, pref)
    }
    return res
};

function helper(w: string, p: string): number {
    let len1 = w.length
    let len2 = p.length
    if (len1 < len2) {
        return 0
    }
    let i = -1
    while (++i < len2) {
        if (w[i] == p[i])
            continue
        return 0
    }
    return 1
};
