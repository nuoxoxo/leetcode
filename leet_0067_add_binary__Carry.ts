function addBinary(a: string, b: string): string {
    let la = a.length    
    let lb = b.length
    let lmax = Math.max(la, lb)
    let diff = Math.abs(la - lb)
    let E = ''
    let s = '0'.repeat(diff)
    if (la != lmax)
        a = s + a
    if (lb != lmax)
        b = s + b
    let i = -1;
    while (++i < lmax)
        E += (parseInt(a[i]) + parseInt(b[i])).toString()
    console.log(E)
    let carry = 0
    let res = ''
    E = E.split("").reverse().join("")
    for (let c of E) {
        if (c == '0') {
            if (carry == 0)
                res += '0'
            else {
                res += '1'
                carry -= 1
            }
        } else if (c == '1') {
            if (carry == 0)
                res += '1'
            else
                res += '0'
        } else if (c == '2') {
            if (carry == 0) {
                carry += 1
                res += '0'
            } else {
                res += '1'
            }
        }
    }
    if (carry != 0)
        i = -1
        while (++i < carry)
            res += '1'
    return res.split('').reverse().join('')
};
