function findMaxConsecutiveOnes(nums: number[]): number {
    let r = 0
    let t = 0
    for (let n of nums) {
        if (n == 0) {
            r = Math.max(r, t)
            t = 0
        } else {
            t += 1
        }
    return Math.max(r, t)
};
