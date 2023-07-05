function longestSubarray(nums: number[]): number {
    let tt:number = 1
    let L:number = 0
    let R:number = -1
    while (++R < nums.length) {
        if (nums[R] === 0) {
            --tt
        }
        if (tt < 0) {
            if (nums[L] === 0) {
                ++tt
            }
            ++L
        }
    }
    return nums.length - 1 - L
};
