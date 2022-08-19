func isPossible(nums []int) bool {
    freq := make(map [int] int)
    subs := make(map [int] int)
    for _, n := range nums {
        freq[n]++
    }
    for _, n := range nums {
        if freq[n] == 0 {
            continue
        }
        freq[n]--
        if subs[n - 1] > 0 {
            subs[n - 1]--
            subs[n]++
        } else if freq[n + 1] > 0 && freq[n + 2] > 0 {
            freq[n + 1]--
            freq[n + 2]--
            subs[n + 2]++
        } else {
            return false
        }
    }
    return true
}
