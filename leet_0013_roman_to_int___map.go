func romanToInt(s string) int {
    dp := map[string] int {
        // voldemort group
        "V":  5,
        "L":  50,
	"D":  500,
        "M":  1000,

	// i group
        "I":  1,
	"IV": 4,
        "IX": 9,

        // x group
	"X":  10,
	"XL": 40,
	"XC": 90,

        // c Group
	"C":  100,
	"CD": 400,
	"CM": 900,
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
