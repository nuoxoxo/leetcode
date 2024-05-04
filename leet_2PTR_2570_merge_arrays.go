func mergeArrays(nums1 [][]int, nums2 [][]int) [][]int {

    res := [][]int{}
    i, j := 0, 0
    n1, n2 := len(nums1), len(nums2)
    for i < n1 && j < n2 {
        a, b := nums1[i][0], nums1[i][1]
        c, d := nums2[j][0], nums2[j][1]
        if a == c {
            i++
            j++
            res = append(res, []int{a, b + d})
        } else if a < c {
            i++
            res = append(res, []int{a, b})
        } else if a > c {
            j++
            res = append(res, []int{c, d})
        }
    }
    for i < n1 {
        res = append(res, []int{nums1[i][0], nums1[i][1]})
        i++
    }
    for j < n2 {
        res = append(res, []int{nums2[j][0], nums2[j][1]})
        j++
    }
    return res
}
