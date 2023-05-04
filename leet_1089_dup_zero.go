func duplicateZeros(arr []int)  {
    i := 0
    for i < len(arr) - 1 {
        if arr[i] == 0 {
            arr = arr[:len(arr) - 1]
            tmp := append(arr[:i], 0)
            arr = append(tmp, arr[i:]...)
            i += 2
        } else {
            i += 1
        }
    }
}
