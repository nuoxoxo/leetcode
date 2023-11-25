function getSumAbsoluteDifferences(nums: number[]): number[] {

    let res: number[] = []
    let [L, R] = [0, 0]
    for (let n of nums) {
        R += n
    }
    let i = -1, len = nums.length
    while (++i < len) {
        L += nums[i]
        res.push(nums[i] * (2 * i + 1 - len) - L + R)
        R -= nums[i]
    }
    return res
    /*
    - got a rough idea :: for any index 'i' in a sorted array, its absodiff
        = 
    nums[i] - num[i] 
    nums[i] - num[i - 1] + 
    nums[i] - num[i - 2] + 
        ... 
    nums[i] - nums[0] + 
        ...
    nums[i] + nums[i]
    nums[i + 1] - nums[i] + 
    nums[i + 2] - nums[i] +
        ...
    nums[n - 1] - nums[i]
        =
    pt1 = nums[i] * (i + 1) - sum( nums[:i + 1] )
    pt2 = sum( nums[i:] ) - nums[i] * (n - i)) 
    p1 + p2 = R - L + (i + 1 - n + i) * nums[i]
        -->
    nums[i] * (2 * i - n + 1) - Lsum + Rsum
    */
};
