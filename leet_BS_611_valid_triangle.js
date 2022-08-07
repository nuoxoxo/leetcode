/**
 * @param {number[]} nums
 * @return {number}
 */
var triangleNumber = function(nums) {
    s3 = nums.length
    count = 0
    nums.sort((a, b) => a - b)
    while (--s3 > 1) {
        s1 = 0
        s2 = s3 - 1
        while (s1 < s2) {
            if (nums[s1] + nums[s2] > nums[s3]) {
                count += s2 - s1
                --s2
            } else {
                ++s1
            }
        }
    }
    return count
};
