func checkArithmeticSubarrays(nums []int, l []int, r []int) []bool {

    var res []bool
    for i := 0; i < len(l); i++ {

        // Wrong: sorting sub-slice will sort original slice in Go 
        // tmp = nums[l[i] : r[i] + 1]
        // sort.Ints(tmp)

        // Correct way 1
        tmp := append([]int(nil), nums[l[i] : r[i] + 1] ...)

        // Correct way 2
        // tmp := make([]int, len(nums[l[i] : r[i] + 1]))
        // copy(tmp, nums[l[i] : r[i] + 1])

        len := len(tmp)
        if len < 3 {
            res = append(res, true)
            continue
        }
        sort.Ints(tmp)
        k := tmp[1] - tmp[0]
        ok := true
        j := 2
        for j < len {
            if tmp[j] - tmp[j - 1] != k {
                ok = false
                break
            }
            j++
        }
        res = append(res, ok)
    }
    return res
}
