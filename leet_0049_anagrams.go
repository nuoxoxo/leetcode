func groupAnagrams(strs []string) [][]string {
    D := map[string][]string{}
    res := [][]string{}
    /*
    - sort chars in string in Go
        s := strings.Split(w, "")
        sort.Strings(s)
        return strings.Join(s, "")
    */
    for _, s := range strs {
        tmp := strings.Split(s, "")
        sort.Strings(tmp )
        word := strings.Join(tmp, "")
        D[word] = append(D[word], s)
        /* YOU DONT NEED CHECKING */
        // _, ok := D[word]
        // if ok {
        //     D[word] = append(D[word], s)
        // } else {
        //     D[word] = []string{s}
        // }
    }
    for _, v := range D {
        res = append(res, v)
    }
    return res
}
