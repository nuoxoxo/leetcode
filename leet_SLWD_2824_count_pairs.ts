function countPairs(nums: number[], target: number): number {
    let l:number = 0
    let r:number = nums.length - 1
    let res:number = 0
    nums.sort((a, b) => a - b)
    while (l < r) {
        if (nums[l] + nums[r] < target) {
            res += r - l
            l += 1
        } else {
            r -= 1
        }
    }
    return res
};
