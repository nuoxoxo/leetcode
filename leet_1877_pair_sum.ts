function minPairSum(nums: number[]): number {
    nums.sort((a, b) => a - b)
    // console.log(nums)
    let len:number = nums.length
    let res:number = Number.MIN_SAFE_INTEGER
    let i:number = -1
    while (++i < len) {
        res = Math.max(res, nums[i] + nums[len - i - 1])
    }
    return res
};
