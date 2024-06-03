func appendCharacters(s string, t string) int {

    solutions := []func(string, string)int{
        // Iterative,
        Recursive,
    }
    return solutions[0](s, t)
}

func Recursive(s, t string) int {

    var recurse func(int, int) int
    recurse = func(is, it int) int {
        if it == len(t) {
            return 0
        }
        if is == len(s) {
            return len(t) - it
        }
        if s[is] == t[it] {
            return recurse(is + 1, it + 1)
        }
        return recurse(is + 1, it)
    }
    return recurse(0, 0)
}

func Iterative(s, t string) int {

    is, it := 0, 0
    for is < len(s) && it < len(t) {
        if s[is] == t[it] {
            it++
        }
        is++
    }
    return len(t) - it
}
