func longestPalindrome(s string) string {

    size := len(s)
    if size == 1 {
        return s
    }

    head := 0
    tail := 1
    var L, R int
    var dist int
    i := 1

    for i < size {

        L = i - 1
        R = i

        for R < size && L > -1 && s[L] == s[R] {
            dist = R - L + 1
            if tail < dist {
                tail = dist
                head = L
            }
            L--
            R++
        }

        L = i - 1
        R = i + 1

        for R < size && L > -1 && s[L] == s[R] {
            dist = R - L + 1
            if tail < dist {
                tail = dist
                head = L
            }
            L--
            R++
        }
        i++
    }

    return s[head : head + tail]
}
