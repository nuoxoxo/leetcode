function isValid(s: string): boolean {
    let len = s.length
    if (len == 0)
        return true
    if (len % 2)
        return false
    let D = []

    // create map/dict: 1st way

    let P = {')': '(', '}': '{', ']': '['}

    // create map/dict: 2nd way

    // let P = new Object()
    // P[')'] = '('
    // P['}'] = '{'
    // P[']'] = '['
    
    for (let c of s) {
        if (!P.hasOwnProperty(c)) {
            D.push(c)
        } else if (D.length != 0 && P[c] == D[D.length - 1]) {
            D.pop()
        } else {
            return false
        }
        console.log(D)
    }
    return (D.length == 0)

};
