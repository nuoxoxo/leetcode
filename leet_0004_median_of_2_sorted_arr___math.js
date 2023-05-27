/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    nums1 = nums1.concat(nums2)
    nums1.sort((a, b) => a - b)
    len = nums1.length
    mid = Math.floor(len / 2)
    if (len % 2 == 0)
        return (nums1[mid - 1] + nums1[mid]) / 2
    return nums1[mid]
};
