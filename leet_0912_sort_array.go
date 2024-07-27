func sortArray(nums []int) []int {

    var MergeSort func(int, int)[]int

    //  [5,2,3,1]
    //  [5,2]   [3,1]
    //  [5] [2] [3] [1] <--- single elements/ end of Dividing
    //  [5] [2] [3] [1] <--- sorting happens/ while Merging
    //       ^
    //               ^  <--- [2,5][1,3]
    //  [2,5]   [1,3]   <--- sorting/merging cont.
    //           ^      <--- [1]
    //   ^              <--- [1,2]
    //             ^    <--- [1,2,3]
    //  [1,2,3,5]

    MergeSort = func(li, ri int)[]int{

        // divide
        if li > ri {
            return []int{}
        }
        if li == ri {
            return []int{nums[li]}
        }
        mid := (ri - li) / 2 + li
        lnums := MergeSort(li, mid)
        rnums := MergeSort(mid + 1, ri)

        // merging
        llen, rlen := len(lnums), len(rnums)
        l, r := 0, 0
        curr := 0
        res := make([]int, llen + rlen)
        for l < llen && r < rlen {
            if lnums[l] < rnums[r] {
                res[curr] = lnums[l]
                curr++
                l++
            } else {
                res[curr] = rnums[r]
                curr++
                r++
            } 
        } 
        for l < llen {
            res[curr] = lnums[l]
            curr++
            l++
        }
        for r < rlen {
            res[curr] = rnums[r]
            curr++
            r++
        }
        return res
    }

    return MergeSort(0, len(nums) - 1)
}
