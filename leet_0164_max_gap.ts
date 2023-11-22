function maximumGap(nums: number[]): number {
    let len = nums.length
    let res = 0
    if (len < 2)
        return 0
    nums.sort((a, b) => a - b)
    let i = 0
    while (++i < len)
        res = Math.max(res, nums[i] - nums[i - 1])
    return res
};
