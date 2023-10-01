function sortArrayByParity(nums: number[]): number[] {
    const n = nums.length
    let pos = 0
    let i = -1
    while (++i < n) {
        if (nums[i] % 2)
            continue
        [nums[pos], nums[i]] = [nums[i], nums[pos]];
        pos++
    }

    return nums
};
