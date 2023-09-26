function removeDuplicateLetters(s: string): string {
    let seen = new Set()
    let count = {}
    let res = ''
    for (let c of s)
        count[c] = (count[c] || 0) + 1
    for (let c of s) {
        if (!seen.has(c)) {
            while (res !== '' && res[res.length - 1].charCodeAt(0) > c.charCodeAt(0) && count[res[res.length - 1]] > 1) {
                seen.delete(res[res.length - 1])
                count[res[res.length - 1]] --
                res = res.substring(0, res.length - 1)
            }
            seen.add(c)
            res += c
        } else {
            count[c] --
        }
    }
    return res
};
