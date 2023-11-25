func findDiagonalOrder(nums [][]int) []int {
    D := make( map[int][]int )
    r := 0
    colmax := 0
    var c int
    for r < len(nums) {
        c = 0 
        for c < len(nums[r]) {
            D[r + c] = append(D[r + c], nums[r][c])
            c++
            colmax = max(colmax, r + c)
        }
        r++
    }
    // fmt.Println(D)
    var res []int
    //  Perks of Go : key order is undefined when traversing a map like this:
    /*
    for _, k := range keys {
        arr := D[k]
        for len(arr) > 0 {
            res = append(res, arr[len(arr) - 1])
            arr = arr[ : len(arr) - 1]
        }
    }
    */

    //  Correct way : keep track of max col and use this as a guide of keys
    i := 0
    for i < colmax {
        arr := D[i]
        for len(arr) > 0 {
            res = append(res, arr[len(arr) - 1])
            arr = arr[ : len(arr) - 1]
        }
        i++
    }
    return res
}

