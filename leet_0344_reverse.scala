object Solution {
    def reverseString(s: Array[Char]): Unit = {

        var i = 0
        var N = s.length
        for (i <- 0 until N / 2) {
            var tmp = s(i)
            s(i) = s(N - i - 1)
            s(N - i - 1) = tmp
        }
    }
}
/*
func reverseString(s []byte)  {
    i, N := 0, len(s)
    for i < N / 2 {
        s[i], s[N - i - 1] = s[N - i - 1], s[i]
        i += 1
    }
}
*/
