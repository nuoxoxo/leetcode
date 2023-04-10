function partitionString(s: string): number {
    let E = new Set()
    let res = 0
    let i = -1
    while (++i < s.length) {
        if (E.has(s[i])) {
            ++res
            E.clear()
        }
        E.add(s[i])
    }
    return res + 1
};
