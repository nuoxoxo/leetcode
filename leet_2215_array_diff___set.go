func findDifference(nums1 []int, nums2 []int) [][]int {
    s1 := map[int]bool{}
    for _, n := range nums1 {
        if !s1[n] {
            s1[n] = true
        }
    }

    s2 := map[int]bool{}
    for _, n := range nums2 {
        if !s2[n] {
            s2[n] = true
        }
    }

    a1 := []int{}
    a2 := []int{}
    for n, _ := range s1 {
        if !s2[n] {
            a1 = append(a1, n)
        }
    }
    for n, _ := range s2 {
        if !s1[n] {
            a2 = append(a2, n)
        }
    }
    return [][]int{a1, a2}
}
