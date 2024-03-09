func getCommon(nums1 []int, nums2 []int) int {
    Solutions := []func([]int,[]int)int{
        Two_pointers, // Best
        Binary_search,
    }
    return Solutions[0](nums1, nums2)

}

func Binary_search(n1 []int, n2 []int) int {
    N := len( n2 )
    for _, v := range n1 {
        l, r := 0, N - 1
        for l <= r {
            m := (r - l) / 2 + l
            mid := n2[m]
            if mid == v {
                return v
            } else if mid < v {
                l = m + 1
            } else {
                r = m - 1
            }
        }
    }
    return -1
}

func Two_pointers(n1 []int, n2 []int) int {
    L, R := len(n1), len(n2)
    l, r := 0, 0
    for l < L && r < R {
        if n1[l] == n2[r] {
            return n1[l]
        } else if n1[l] < n2[r] {
            l++
        } else {
            r++
        }
    }
    return -1
}
