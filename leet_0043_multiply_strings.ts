function multiply(num1: string, num2: string): string {
    if (num1 == '0' || num2 == '0') {
        return '0'
    }
    let len1 = num1.length
    let len2 = num2.length
    let zero = '0'.charCodeAt(0)
    let res = ''
    let p = new Array(len1 + len2).fill(0)
    let i = len1
    while (--i > -1) {
        let j = len2
        while (--j > -1) {

            // way 1
            let L = num1[i].charCodeAt(0) - zero
            let R = num2[j].charCodeAt(0) - zero
            let temp = L * R + p[i + j + 1]
            p[i + j] = Math.floor(temp / 10) + p [i + j]
            p[i + j + 1] = temp % 10

            // way 2
            /*
            let L = i + j
            let R = L + 1
            let temp = (num1[i].charCodeAt(0) - zero) *
                (num2[j].charCodeAt(0) - zero) + p[R]
            p[L] = Math.floor(temp / 10) + p[L]
            p[R] = temp % 10
            */
        }
    }  
    // way 1
    /*
    i = 0
    while (p[i] == 0)
        ++i
    while (i < len1 + len2) {
        res += p[i].toString()
        ++i
    }*/

    // way 2
    res = p.join('').replace(/^0+/, '')
    return res
};
