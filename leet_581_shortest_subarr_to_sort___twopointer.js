/**
 * @param {number[]} nums
 * @return {number}
 */
var findUnsortedSubarray = function(nums) {
    n = nums.length
    if (n < 2)
        return 0
    prev = nums[0]
    tail = 0
    i = 0
    while (++i < n) {
        if (prev > nums[i])
            tail = i
        else
            prev = nums[i]
    }
    if (tail == 0)
        return 0
    prev = nums[n - 1]
    head = n - 1
    i = n - 1
    while (--i > -1) {
        if (nums[i] > prev)
            head = i
        else
            prev = nums[i]
    }
    return tail + 1 - head
};
