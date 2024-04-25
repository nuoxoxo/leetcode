func lengthOfLIS(nums []int) int {

    Solutions := []func([]int) int {
        // LowerBound,
        // nSquare,
        BinarySearch,
    }
    return Solutions[0](nums)
}

func LowerBound(nums []int) int {

    lens := []int{}
    for _, n := range nums {
        idx := sort.SearchInts(lens, n)
        if idx == len(lens) {
            lens = append(lens, n)
        } else {
            lens[idx] = n
        }
    }
    return len(lens)
}

func BinarySearch(nums[]int)int{

    lens := []int{}
    for _, n := range nums {
        N := len(lens)
        if N == 0 || lens[N - 1] < n {
            lens = append(lens, n)
        } else {
            L := 0
            R := N - 1
            for L < R {
                mid := (R - L) / 2 + L
                if lens[mid] < n {
                    L = mid + 1
                } else {
                    R = mid
                }
            }
            lens[R] = n
        }
    }
    return len(lens)
}

func nSquare(nums[]int)int{

    N := len(nums)
    INF := 2147483648
    lens := make([]int64, N + 1)
    for i := range lens {
        lens[i] = int64(INF)
    }
    lens[0] = -int64(INF)
    for _, n := range nums {
        for i := 0; i < N+1; i++ {
            if lens[i] < int64(n) {
                if lens[i+1] > int64(n) {
                    lens[i+1] = int64(n)
                }
            }
        }
    }
    res := -1
    i := N
    for i > -1 {
        if lens[i] != int64(INF) {
            res = i
            break
        }
        i--
    }
    return res
}

