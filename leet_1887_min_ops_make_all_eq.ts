function reductionOperations(nums: number[]): number {

    // way 1

    /*
    let res: number = 0
    nums.sort((a, b) => a - b)
    let i = 0
    while (++i < nums.length) {
        if (nums[i] ^ nums[i - 1]) {
            res += nums.length - i
        }
    }
    return res
    */

    // way 2

    let res: number = 0
    let dis: number = 0
    nums.sort((a, b) => a - b)
    let i = 0
    while (++i < nums.length) {
        if (nums[i] ^ nums[i - 1]) {
            dis += 1
        }
        res += dis
    }
    return res
};
