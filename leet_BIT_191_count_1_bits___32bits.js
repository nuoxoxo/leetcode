var hammingWeight = function(n) {
    let res = 0
    let i = 33
    let x = 1
    while (--i){
        if (n & x)
            res++
        x <<= 1
    }
    return res
};
