func convert(s string, numRows int) string {
    if numRows < 2 {
        return s
    }
    n := len(s)
    res := ""
    for i := 0; i < numRows; i++ {
        r := 2 * (numRows - 1)
        c := i
        for c < n {
            res += string(s[c])
            in_between := r + c - (i * 2) // must-have parenthesis
            if i < numRows - 1 && i > 0 && in_between < n {
                res += string(s[in_between])
            }
            c += r
        }
    }
    return res
}
