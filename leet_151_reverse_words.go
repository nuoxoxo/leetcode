func reverseWords(s string) (a string) {
	arr := strings.Split(s, " ")
	n := len(arr) - 1
	for i:= n ; i >= 0; i-- {
		cl := len(arr[i])
		if cl > 0 && len(a) > 0 {
			a += " " + arr[i]
		} else if cl > 0 {
			a += arr[i]
		}
	}
	return
}
