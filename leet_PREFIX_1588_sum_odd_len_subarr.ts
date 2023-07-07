function sumOddLengthSubarrays(arr: number[]): number {
    let len: number = arr.length
    let res: number = 0
    let i: number = -1
    while (++i < len){
        let j: number = 0
        let tmp: number = 0
        while (i + j < len){
            tmp += arr.slice(i, i + j + 1).reduce((t, s) => t + s, 0)
            j += 2
        }
        res += tmp
    }
    return res
};
