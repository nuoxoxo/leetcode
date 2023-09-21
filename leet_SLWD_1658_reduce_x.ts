function minOperations(nums: number[], x: number): number {
    let tt = nums.reduce((acc, res) => acc + res, 0)
    let len = nums.length
    let window = -1
    let temp = 0
    let R = -1
    let L = 0
    while (++R < len) {
        temp += nums[R]
        while (temp > tt - x && L <= R) {
            temp -= nums[L++]
        }
        if (temp == tt - x) {
            window = Math.max(window, R - L + 1);
        }
    }
    return window === -1 ? -1 : len - window
};

