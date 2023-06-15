/**
 Do not return anything, modify nums in-place instead.
 */

function moveZeroes(nums: number[]): void {
    let size = nums.length
    if (size == 0) {
        return 
    }
    let i = 0
    let x = 0
    while (i < size) {
        if (nums[i] != 0) {
            if (i != x) {
                let tmp = nums[i]
                nums[i] = nums[x]
                nums[x] = tmp
            }
            x++
        }
        i++
    }
};
