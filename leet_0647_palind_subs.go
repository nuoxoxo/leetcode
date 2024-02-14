func countSubstrings(s string) int {
    solutions := []func(string)int{
        Solution_odd_even_2pass,
    }
    return solutions[0](s)
}

func Solution_odd_even_2pass(s string)int{
    N := len(s)
    var i, L, R int
    res := 0
    i = 0
    for i < N {
        L, R = i, i
        for L > -1 && R < N {
            if s[L] == s[R] {
                L--
                R++
                res++
            } else {
                break
            }
        }
        i++
    }
    i = 0
    for i < N {
        L, R = i, i + 1
        for L > -1 && R < N {
            if s[L] == s[R] {
                L--
                R++
                res++
            } else {
                break
            }
        }
        i++
    }
    return res
}
