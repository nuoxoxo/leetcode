func findDuplicate(nums []int) int {
    Solutions := []func([]int) int {
        // Binary_search,
        Naive,
    }
    return Solutions[0](nums)
}

func Binary_search(nums[]int) int {
    N := len(nums)
    if N < 3 {
        return nums[0]
    }
    sort.Ints(nums)
    mid := N / 2
    if nums[mid - 1] == nums[mid] || nums[mid] == nums[mid + 1] {
        return nums[mid]
    }
    l, r := 1, N - 2
    for l != mid && r != mid {
        if nums[l - 1] == nums[l] { return nums[l] }
        if nums[r + 1] == nums[r] { return nums[r] }
        l++
        r--
    }
    return 1000000000000000000
}

func Naive(nums[]int) int {
    N := len(nums)
    if N < 3 {
        return nums[0]
    }
    sort.Ints(nums)
    i := 1
    for i < N {
        if nums[i - 1] == nums[i] {
            break
        }
        i++
    }
    return nums[i]
}

