func convert(s string, numRows int) string {
    if numRows < 2 {
        return s
    }
    // arr := [numRows] string {} // non-constant array bound
    arr := make([] string, numRows)
    n := len(s)
    res := ""
    r := 0
    for i := 0; i < n; i++ {
        arr[r] += string(s[i])
        c := i / (numRows - 1)
        if c % 2 == 1 {
            r--
        } else {
            r++
        }
    }
    for _, tmp := range arr {
        res += tmp
    }
    return res
}
