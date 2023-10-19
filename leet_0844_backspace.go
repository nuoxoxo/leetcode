func backspaceCompare(s string, t string) bool {
    ss := []rune{}
    tt := []rune{}
    for _, c := range s {
        if c != '#' {
            ss = append(ss, c)
        } else if len(ss) > 0 {
            ss = ss[:len(ss) - 1]
        }
    }
    for _, c := range t {
        if c != '#' {
            tt = append(tt, c)
        } else if len(tt) > 0 {
            tt = tt[:len(tt) - 1]
        }
    }
    return string(ss) == string(tt)
}
