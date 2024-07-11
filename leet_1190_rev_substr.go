func reverseParentheses(s string) string {

    Q := []int{}
    // res := ""
    res := []rune{}
    for _, char := range s {

        if char == '(' {
            Q = append(Q, len(res))
        } else if (char == ')') {
            left := Q[len(Q) - 1]
            Q = Q[:len(Q) - 1]
            strrev(res, left)
        } else {
            res = append(res, char)
        }
    }
    return string(res)//res
}

func strrev(s []rune, left int) {
	for l, r := left, len(s) - 1; l < r; l, r = l + 1, r - 1 {
		s[l], s[r] = s[r], s[l]
	}
}

/*
    {
        deque<int> Q;
        string res;
        for (char c : s)
        {
            if (c == '(')
            {
                Q.push_back( res.length() );
            }
            else if (c == ')')
            {
                int left = Q.back();
                Q.pop_back();
                reverse(begin(res) + left, end(res));
            }
            else
            {
                res += c;
            }
        }
        return res;
    }
*/

