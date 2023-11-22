import (
	"sort"
	"strconv"
	"strings"
)

func largestNumber(nums []int) string {
    var S []string
    for _, n := range nums {
        S = append(S, strconv.Itoa(n))
    }
    sort.Slice(S, func (i, j int) bool {
        return S[i] + S[j] > S[j] + S[i]
    })
    res := strings.Join(S, "")
    i := 0
    for i < len(res) && res[i] == '0' {
        i++
    }
    if i == len(res) {
        return "0"
    }
    return res
}
