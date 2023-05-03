function arraySign(nums: number[]): number {
    let sign = 1
    for (let n of nums) {
        if (n == 0) {
            return 0
        }
        if (n < 0) {
            sign = -sign
        }
    }
    return sign > 0 ? 1 : -1
};
