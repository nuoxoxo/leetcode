func frequencySort(nums []int) []int {

    counter := make([]int, 201)
    for _, n := range nums {
        counter[n + 100]++
    }
    sort.Slice(nums, func(l, r int)bool{
        L, R := nums[l], nums[r]
        if counter[L + 100] == counter[R + 100] {
            return L > R
        }
        return counter[L + 100] < counter[R + 100]
    })
    return nums
}
