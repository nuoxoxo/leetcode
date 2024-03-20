func firstUniqChar(s string) int {
    Solutions := []func(string) int {
        // Constant_space_TLE,
        Constant_space_2pass,
    }
    return Solutions[ 0 ]( s )
}

func Constant_space_2pass(s string) int {
    D := make([]int, 26)
    for i, _ := range D {
        D[i] = 0
    }
    for _, c := range s {
        D[c - 'a']++
    }
    for i, c := range s {
        if D[ c - 'a' ] == 1 {
            return i
        }
    }
    return -1
}

func Constant_space_TLE(s string) int {
    for i, c := range s {
        if i == len(s) - 1 && ! strings.Contains(s[:i], string(c)) ||
        i == 0 && !strings.Contains(s[1:], string(c)) ||
        !strings.Contains(s[:i] + s[i + 1:], string(c)) {
            return i
        }
    }
    return -1
}

