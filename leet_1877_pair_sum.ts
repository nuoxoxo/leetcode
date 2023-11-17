function minPairSum(nums: number[]): number {

    // new soln
    let len = nums.length
    let l = 0, r = len - 1
    let res = 0
    nums.sort((a, b) => a - b)
    while (l < r) {
        res = Math.max(res, nums[l++] + nums[r--])
    }
    return res

    /*
    nums.sort((a, b) => a - b)
    // console.log(nums)
    let len:number = nums.length
    let res:number = Number.MIN_SAFE_INTEGER
    let i:number = -1
    while (++i < len) {
        res = Math.max(res, nums[i] + nums[len - i - 1])
    }
    return res
    */
};
