func maximumElementAfterDecrementingAndRearranging(arr []int) int {
    // way 1
    /*
    sort.Ints(arr)
    arr[0] = 1
    res := 1
    i := 1
    for i < len(arr) {
        if arr[i] > arr[i - 1] {
            arr[i] = arr[i - 1] + 1
        }
        if arr[i] > res {
            res = arr[i]
        }
        i++
    }
    */

    // way 2
    sort.Ints(arr)
    res := 0
    for _, n := range arr {
        if res + 1 > n {
            res = n
        } else {
            res++
        }
    }

    return res
}
