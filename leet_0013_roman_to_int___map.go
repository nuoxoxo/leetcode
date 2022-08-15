func romanToInt(s string) int {
    dp := map[string] int {

        // voldemort group
        "V":  5,
        "L":  50,
	"D":  500,
        "M":  1000,

	// i x c group
        "I":  1,
	"X":  10,
	"C":  100,

    }
    size := len(s)
    res := 0
    i := 0
    for i < size {
        self := dp[string(s[i])]
        // next := i + 1 < size ? dp[s[i + 1]] : 0 // no ternary in go
        next := 0
        if i + 1 < size {
            next = dp[string(s[i + 1])]
        }
        if self < next {
            res += next - self
            i++
        } else {
            res += self
        }
        i++
    }
    return res
}
