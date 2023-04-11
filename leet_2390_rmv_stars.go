import "strings"

func removeStars(s string) string {
    a := [] byte {}
    for _, c := range s {
        if c == '*' && len(a) != 0 {
            a = a[:len(a) - 1]
        } else if c != '*' {
            a = append(a, byte(c))
        }
    }
    return string(a)
}
