function truncateSentence(s: string, k: number): string {
    let r = ''
    for (let c of s) {
        if (c == ' ')
            --k
        if (k == 0)
            break
        r += c
    }
    return r
};
