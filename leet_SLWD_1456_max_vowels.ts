function maxVowels(s: string, k: number): number {
    let v = 'aeiou'
    let L = 0, R = -1
    let temp = 0
    let res = 0
    while (++R < s.length) {
        if (v.includes(s[R])) {
            ++temp
        }
        if (R - L == k) {
            if (v.includes(s[L])) {
                --temp
            }
            ++L
        }
        res = res > temp ? res : temp
    }
    return res

};
