function differenceOfSum(nums: number[]): number {
    let res1 = 0
    let res2 = 0
    for (let n of nums) {
        res1 += n
        while (n ^ 0) {
            res2 += n % 10
            n /= 10
        }
    }
    let diff = res1 - res2;
    return diff > 0 ? diff : -diff 
};
