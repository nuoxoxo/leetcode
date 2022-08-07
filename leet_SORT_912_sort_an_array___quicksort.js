/**
 * @param {number[]} nums
 * @return {number[]}
 */

var sortArray = function(nums) {
    quicksort(nums, 0, nums.length - 1)
    return nums
};

function quicksort(arr, L, R) {
    if (L >= R)
        return
    let i = L
    let j = R
    let piv = Math.floor(Math.random() * (R - L) + L)
    let val = arr[piv]
    while (i <= j) {
        while (arr[i] < val)
            ++i
        while (arr[j] > val)
            --j
        if (i <= j) {
            let tmp = arr[i]
            arr[i] = arr[j]
            arr[j] = tmp
            ++i
            --j
        }
    }
    quicksort(arr, L, j)
    quicksort(arr, i, R)
}
