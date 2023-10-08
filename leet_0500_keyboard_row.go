func findWords(words []string) []string {

	var res []string
	for _, w := range words {
		if checker("qwertyuiop", w) || checker("asdfghjkl", w) || checker("zxcvbnm", w) {
			res = append(res, w)
		}
	}
	return res
}

func checker(charset string, word string) bool {

	for _, c := range word {
		if strings.Index(charset, string(unicode.ToLower(c))) == -1 {
            fmt.Println(string(c), word, charset)
			return false
		}
	}
	return true
}
