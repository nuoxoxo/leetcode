/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    let size = nums.length
    if (size == 1)  return 1
    nums.sort( (a, b) => {return a - b} )
    console.log(nums)
    let len = 0
    let i = 0
    while (i < size - 1) {
        let tmp = 1
        let j = i + 1
        while (j < size && (nums[j] - nums[j - 1] == 1 || nums[j] - nums[j - 1] == 0)) {
            if (nums[j] - nums[j - 1] == 1)
                ++tmp
            ++j
        }
        len = Math.max(len, tmp)
        i = j
    }
    return len
};
