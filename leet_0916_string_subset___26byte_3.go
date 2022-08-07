
func wordSubsets(words1 []string, words2 []string) []string {
    freq := [26] byte {}
    res := [] string {}

    //for pos, char := range "日本語"
    for _, s := range words2 {
        temp := [26] byte {}

        for _, c := range s {
            temp[c - 'a']++
            if freq[c - 'a'] < temp[c - 'a'] {
                freq[c - 'a'] = temp[c - 'a']
            }
        }
    }
    for _, s := range words1 {
        temp := [26] byte {}

        for _, c := range s {
            temp[c - 'a']++
        }
        flag := true
        for j := 0; j < 26; j++ {
            if temp[j] < freq[j] {
                flag = false
            }
        }
        if flag {
            res = append(res, s)
        }
    }
    return res
}
