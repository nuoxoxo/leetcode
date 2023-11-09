const MD = int(1e9 + 7)
	var res, dis, i int
	c := rune(s[0])

	for i = 1; i < len(s); i++ {
		if c == rune(s[i]) {
			dis++
		} else {
			res = (res + (dis * (dis + 1) / 2) % MD) % MD
			dis = 1
			c = rune(s[i])
		}
	}

	res = (res + (dis * (dis + 1) / 2) % MD) % MD
	return res
