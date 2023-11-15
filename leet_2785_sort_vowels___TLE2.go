func sortVowels(s string) string {
    v := "aeiouAEIOU"
    vo := []string{}
	for _, c := range s {
		if strings.ContainsRune(v, c) {
            vo = append(vo, string(c))
		}
	}
	sort.Strings(vo)
	res := ""
	i := 0
	for _, c := range s {
		if !strings.ContainsRune(v, c) {
			res += string(c)
		} else {
			// res += string(vo[i])
            res += vo[i]
			i++
		}
	}
	return res
}
