var isHappy = function(n) {
    let E = new Set()
    while (true){
        n = makeHappy(n)
        if (n == 1) break
        if (E.has(n))
            return false
        E.add(n)
    }
    return true 
};

var makeHappy = (n) => {
    res = 0
    while (n != 0) {
        let tmp = (n % 10) * (n % 10)
        res += tmp
        n = Math.floor(n / 10)
    }
    return res
}
