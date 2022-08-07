
func wordSubsets(words1 []string, words2 []string) []string {
    var     freq [26] byte
    var     res [] string

    for i := 0; i < len(words2); i++ {
        var     temp [26] byte

        for j := 0; j < len(words2[i]); j++ {
            temp[words2[i][j] - 'a']++
            if freq[words2[i][j] - 'a'] < temp[words2[i][j] - 'a'] {
                freq[words2[i][j] - 'a'] = temp[words2[i][j] - 'a']
            }
        }
    }
    for i := 0; i < len(words1); i++ {
        var     temp [26] byte

        for j := 0; j < len(words1[i]); j++ {
            temp[words1[i][j] - 'a']++
        }
        flag := true
        for j := 0; j < 26; j++ {
            if temp[j] < freq[j] {
                flag = false
            }
        }
        if flag {
            res = append(res, words1[i])
        }
    }
    return res
}
