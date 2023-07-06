function minSubArrayLen(target: number, nums: number[]): number {
    if (nums.indexOf(target) > -1) {
        return 1
    }
    let len: number = nums.length
    let res: number = Number.MAX_SAFE_INTEGER
    let temp: number = 0
    let found: boolean = false
    let L: number = 0
    let R: number = -1
    while (++R < len) {
        temp += nums[R]
        if (temp >= target) {
            found = true
        }
        while (temp >= target) {
            temp -= nums[L]
            res = Math.min(res, R - L + 1)
            ++L
        }
    }
    return found ? res : 0
};
