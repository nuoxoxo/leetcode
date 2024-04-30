func minimumAddedInteger(nums1 []int, nums2 []int) int {
    sort.Ints(nums1)
    sort.Ints(nums2)
    // fmt.Println(nums1)
    // fmt.Println(nums2)
    N := len(nums1)
    res := 42
    stop := false
    l := 0
    for l < N - 1 {
        if stop {
            break
        }
        r := l + 1
        for r < N {
            // ALT := []int{}
            // ALT = append(ALT, nums1[:l] ...)
            // ALT = append(ALT, nums1[l + 1:r] ...)
            // ALT = append(ALT, nums1[r + 1:] ...)
            ALT := pop2elems(nums1, l, r)
            if OK(ALT, nums2) {
                res = nums2[0] - ALT[0]
                stop = true
                break
            }
            r++
        }
        l++
    }
    return res
}

func OK(L, R []int) bool {

    diff := L[0] - R[0]
    N := len(L)
    i := 0
    for i < N {
        if L[i] - R[i] != diff {
            return false
        }
        i++
    }
    return true
}

func pop2elems(A []int, l, r int) []int {

    res := []int{}
    res = append(res, A[:l] ...)
    res = append(res, A[l + 1:r] ...)
    res = append(res, A[r + 1:] ...)
    return res
}
