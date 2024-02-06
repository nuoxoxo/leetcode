func groupAnagrams(strs []string) [][]string {
    Solutions := []func([]string)[][]string{
        Solution_sorted_bytes_as_key,
        Solution_sorted_runes_as_key,
        Solution_sort_with_named_result_params,
        Solution_sort_string,
    }
    return Solutions[ 0 ]( strs )
}

// Solution 2.1 - same as 2 but sorted Bytes array as Key

func Solution_sorted_bytes_as_key(strs[]string)[][]string{
    D := map[[26]byte][]string{}
    for _, s := range strs {
        key := str_to_sorted_bytes(s)
        D[key] = append(D[key], s)
    }
    res := make([][]string, 0, len(D))
    for _, v := range D {
        res = append(res, v)
    }
    return res
}

func str_to_sorted_bytes(s string) (bytes [26]byte) {
    for _, c := range s {
        bytes[ c - 'a' ]++
    }
    return
}

// Solution 2 - array of sorted runes as Key

func Solution_sorted_runes_as_key(strs[]string)[][]string{
    D := map[[26]rune][]string{}
    for _, s := range strs {
        key := str_to_sorted_runes(s)
        D[key] = append(D[key], s)
    }
    res := make([][]string, 0, len(D))
    for _, v := range D {
        res = append(res, v)
    }
    return res
}

func str_to_sorted_runes(s string) (runes [26]rune) {
    for _, c := range s {
        runes[ c - 'a' ]++
    }
    return
}

// Solution 1

func Solution_sort_with_named_result_params(strs[]string)[][]string{
    D := map[string][]string{}
    for _, s := range strs {
        key := sortedString(s)
        D[key] = append(D[key], s)
    }
    res := make([][]string, 0, len(D))
    for _, v := range D {
        res = append(res, v)
    }
    return res
}

// helper fn using "named result parameters" - doent return anything
func sortedString(s string) (res string) {
    tmp := strings.Split(s, "")
    sort.Strings( tmp )
    res = strings.Join(tmp, "")
    return 
}

// Solution 0

func Solution_sort_string(strs []string)[][]string{
    D := map[string][]string{}
    for _, s := range strs {
        tmp := strings.Split(s, "")
        sort.Strings( tmp )
        key := strings.Join(tmp, "")
        D[key] = append(D[key], s)
    }
    res := make([][]string, 0, len(D))
    for _, v := range D {
        res = append(res, v)
    }
    return res
}
