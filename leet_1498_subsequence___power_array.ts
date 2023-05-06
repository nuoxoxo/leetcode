function numSubseq(nums: number[], target: number): number {
    nums.sort((a, b) => {return a - b})
    let l: number = 0, r = nums.length - 1
    let mod: number = 1e9 + 7 // Math.pow(10, 9) + 7
    let res: number = 0
    let a: number[] = [1]
    let i = 0
    while (++i < nums.length) {
        a.push(a[i - 1] * 2 % mod)
    }
    while (l <= r) {
        if (nums[l] + nums[r] <= target) {            
            res = (res + a[r - l]) % mod
            ++l
        } else {
            --r
        }
    }
    return res % mod
};
