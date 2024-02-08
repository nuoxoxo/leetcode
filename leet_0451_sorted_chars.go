func frequencySort(s string) string {
    counter := make(map[rune]int)
    for _, c := range s {
        counter[c]++
    }
    chars := make([]rune, 0, len(counter))
    for key := range counter {
        chars = append(chars, key)
    }
    sort.Slice(chars, func(l, r int) bool {
        return counter[chars[l]] > counter[chars[r]] ||
            ( counter[chars[l]] == counter[chars[r]] &&
            chars[l] > chars[r])
    })
    // var res string // Error : res += c (mismatched types string and rune)
    var res strings.Builder
    for _, c := range chars {
        // res += c
        res.WriteString(strings.Repeat(string(c), counter[c]))
    }
    return res.String()
}
