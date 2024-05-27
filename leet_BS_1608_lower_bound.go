func specialArray(nums []int) int {
    Solutions := []func([]int)int{
        // Straightforward_iterate,
        Bisect_left,
    }
    return Solutions[0](nums)
}

func Straightforward_iterate(nums []int) int {

    sort.Ints(nums)
    N := len(nums)
    x := 1
    for x < N {
        index := N - x
        if nums[index - 1] < x && nums[index] >= x {
            return x
        }
        x++
    }
    if x <= nums[0] {
        // assert -> x == N
        return N
    }
    return -1
}

func Bisect_left(nums []int) int {

    sort.Ints(nums)
    N := len(nums)
    curr := 0
    for curr < N + 1 {
        L, R := 0, N
        for L < R {
            mid := (R - L) / 2 + L
            n := nums[mid]
            if n < curr {
                L = mid + 1
            } else {
                R = mid
            }
        }
        if curr == N - L {
            return curr
        }
        curr++
    }
    return -1
}
