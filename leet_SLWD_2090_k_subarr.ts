function getAverages(nums: number[], k: number): number[] {
    if (k == 0)
        return nums
    let window:number = 1 + k * 2
    let len:number = nums.length
    if (window > len)
        return ( new Array(len).fill(-1) )
    let res:number[] = Array(len).fill(-1)
    let l: number = 0
    let r: number = -1
    let tt: number = 0
    let avg:number = 0
    while (++r < len) {
        tt += nums[r]
        if (r - l + 1 ^ window)
            continue
        avg = Math.floor(tt / window)
        res[r - k] = avg
        tt -= nums[l]
        ++l
    }
    return res
};
