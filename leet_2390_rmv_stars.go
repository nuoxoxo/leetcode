import "strings"

func removeStars(s string) string {
    a := [] byte {}
    for _, c := range s {
        if c == '*' && len(a) != 0 {
            a = a[:len(a) - 1]
        } else {
            a = append(a, byte(c))
        }
    }
    return string(a)
}
