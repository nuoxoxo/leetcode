function removeStars(s: string): string {
    let a = []
    for (let c of s) {
        if (c == '*' && a.length ^ 0) {
            a.pop()
        } else if (c != '*') {
            a.push(c)
        }
    }
    return a.join('')
};
