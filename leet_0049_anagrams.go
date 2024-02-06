func groupAnagrams(strs []string) [][]string {
    D := map[string][]string{}
    res := [][]string{}
    for _, s := range strs {
        tmp := strings.Split(s, "")
        sort.Strings( tmp )
        word := strings.Join(tmp, "")
        D[word] = append(D[word], s)
    }
    for _, v := range D {
        res = append(res, v)
    }
    return res
}
