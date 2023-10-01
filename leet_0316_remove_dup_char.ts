function removeDuplicateLetters(s: string): string {
    let seen:Record<string, boolean> = {}
    let count:Record<string, number> = {}
    let res:string = ''
    for (let c of s) {
        count[c] = count[c] ? count[c] + 1 : 1
    }
    for (let c of s) {
        if (seen[c]) {
            count[c] -= 1
        } else {
            while (res !== '' && res[res.length - 1].charCodeAt(0) > c.charCodeAt(0) && count[res[res.length - 1]] > 1) {
                seen[res[res.length - 1]] = false
                count[res[res.length - 1]] -= 1
                res = res.substring(0, res.length - 1)
            }
            seen[c] = true
            res += c
        }
    }
    return res
};
