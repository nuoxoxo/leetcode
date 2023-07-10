function minOperations(nums: number[]): number {
    let len: number = nums.length
    let res: number = 0
    let i: number = 0 // start from 1
    while (++i < len) {

        if (nums[i - 1] < nums[i]) {// right order
            continue
        }
        // not strictly incr.
        let need: number = nums[i - 1] - nums[i] + 1
        res += need
        nums[i] = nums[i - 1] + 1

    }
    return res
};
