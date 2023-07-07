function maxConsecutiveAnswers(s: string, k: number): number {
    let len: number = s.length
    let res: number = 0
    let T: number = 0
    let F: number = 0
    let L: number = 0
    let R: number = -1
    while (++R < len) {
        if (s[R] == 'T') {
            ++T
        } else {
            ++F
        }
        while (T > k && F > k) {
            if (s[L] == 'T') {
                --T
            } else {
                --F
            }
            ++L
        }
        res = Math.max(res, R - L + 1)
    }
    return res

};
