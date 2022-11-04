func arrayStringsAreEqual(word1 []string, word2 []string) bool {
    s1 := ""
    s2 := ""
    for _, s := range word1 {
        s1 += s
    }
    for _, s := range word2 {
        s2 += s
    }
    return s1 == s2
}
