function truncateSentence(s: string, k: number): string {
    let r = s.split(' ')
    s = ''
    for (let w of r) {
        if (k-- == 0)
            break
        s += w + ' '
    }
    return s.slice(0, -1)
};
