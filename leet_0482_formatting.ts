function licenseKeyFormatting(s: string, k: number): string {
    let a = s.split('').reverse()
    // console.log(a)
    let r = ''
    let count = 0
    for (let c of a) {
        if (c == '-') {
            continue
        }
        if (count ^ k) {
            count += 1
        } else {
            count = 1
            r += '-'
        }
        r += c.toUpperCase()
    }
    if (r != '' && r[r.length - 1] == '-') {
        r = r.slice(0, -1)
    }
    return r.split('').reverse().join('')
};
