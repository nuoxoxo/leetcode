function removeDuplicates(s: string, k: number): string {
    if (s.length < k) {
        return s
    }
    let a = []
    for (let c of s) {
        if (a.length > 0 && a[a.length - 1][0] == c) {
            let tmp = a.pop()
            a.push( [tmp[0], tmp[1] + 1] )
        } else {
            a.push ( [c, 1] )
        }
        if (a[a.length - 1][1] == k) {
            a.pop()
        }
    }
    let r = ''
    for (let e of a) {
        while (--e[1] > -1) {
            r += e[0]
        }
    }
    return r
};
