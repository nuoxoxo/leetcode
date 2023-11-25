func sortVowels(s string) string {
    // v := "aeiouAEIOU"
    v := map[rune]bool{
        'a':true,
        'e':true,
        'i':true,
        'o':true,
        'u':true,
        'A':true,
        'E':true,
        'I':true,
        'O':true,
        'U':true,
    }
	vo := []rune{}
	for _, c := range s {
		if v[c] {
			vo = append(vo, c)
		}
	}
    // sort.Strings(vo)
    // sort.Ints32(vo)
    sort.Slice(vo, func(a, b int) bool { return vo[a] < vo[b] })
	arr := []rune{}
	i := 0
	for _, c := range s {
		if !v[c] {
			arr = append(arr, c)
		} else {
			arr = append(arr, vo[i])
			i++
		}
	}
    res := string(arr)
	return res
}
