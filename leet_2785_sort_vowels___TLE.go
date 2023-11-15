func sortVowels(s string) string {
    v := "aeiouAEIOU"
    vo := ""
	for _, c := range s {
		if strings.ContainsRune(v, c) {
			vo += string(c)
		}
	}
    tmp := strings.Split(vo, "")
    sort.Strings(tmp)
    vo = strings.Join(tmp, "")
	res := ""
	i := 0
	for _, c := range s {
		if !strings.ContainsRune(v, c) {
			res += string(c)
		} else {
			res += string(vo[i])
			i++
		}
	}
	return res
}
