function searchInsert(nums: number[], target: number): number {
    let i = -1
    while (++i < nums.length) {
        if (nums[i] >= target)
            return i
    }
    return nums.length
};
