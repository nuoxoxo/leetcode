func intersection(nums1 []int, nums2 []int) []int {
    Solutions := []func([]int, []int)[]int{
        Two_pointers,
        Using_dict,
    }
    return Solutions[ 0 ]( nums1, nums2 )
}

func Using_dict(n1[]int, n2[]int)[]int{

    res := []int{}
    D := map[int]int{}
    for _, n := range n1 {
        D[n]++
    }
    for _, n := range n2 {
        _, ok := D[n]
        if ok {
            res = append(res, n)
            delete(D, n)
        }
    }
    return res
}

func Two_pointers(n1[]int, n2[]int)[]int{

    res := []int{}
    sort.Ints(n1)
    sort.Ints(n2)
    l, r := 0, 0
    for l < len(n1) && r < len(n2) {
        L := n1[l]
        if L < n2[r] {
            l++
            continue
        } else if L > n2[r] {
            r++
            continue
        } else if len(res) == 0 || res[len(res) - 1] != L {
            res = append(res, L)
        }
        l++
        r++
    }
    return res

}

