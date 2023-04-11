function removeDuplicates(s: string): string {
    let a = []
    for (let c of s) {
        if (a.length ^ 0 && c == a[0]) {
            a.shift()
        } else {
            a.unshift(c)
        }
    }
    return a.reverse().join('')
};
