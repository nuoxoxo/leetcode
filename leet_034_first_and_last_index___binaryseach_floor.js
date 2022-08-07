/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let     mid, n, i, j;

    n = nums.length
    i = 0;
    j = n - 1;
    while (i <= j) {
        mid = Math.floor((j - i) / 2) + i;
        if (nums[mid] === target) {
            i = j = mid;
            while (i > -1 && nums[i] == target)
                --i;
            while (j < n && nums[j] == target)
                ++j;
            return [i + 1, j - 1]
        } else if (nums[mid] < target) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return [-1, -1];

}
