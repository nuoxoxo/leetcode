var sumOddLengthSubarrays = function(arr) {
    let len = arr.length
    let res = 0
    let i = -1
    while (++i < len){
        let j = 0
        let tmp = 0
        while (i + j < len){
            tmp += arr.slice(i, i + j + 1).reduce((t, s) => t + s, 0)
            j += 2
        }
        res += tmp
    }
    return res 
};
