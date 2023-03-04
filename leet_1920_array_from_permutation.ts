function buildArray(nums: number[]): number[] {
    let r = []
    for (let n of nums)
        r.push(nums[n])
    return r
};
