function countAsterisks(s: string): number {
    let res = 0
    let alt = true
    for (let c of s) {
        if (c == '|') {
            alt = !alt
        }
        if (alt && c == '*') {
            ++res
        }
    }
    return res
};
