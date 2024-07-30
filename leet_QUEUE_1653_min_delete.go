func minimumDeletions(s string) int {

    // Eg.1
    // aababbab - Rule is no B before A, ie. no AB in a stack
    //        ^ b
    //       ^^ ba
    //      ^   b(a + b) ---> b
    //     ^^   b
    //    ^^^   bba
    //   ^      bb(a + b) ---> b
    // ^^^      bba
    // ... so once we meet B after an A, negate them as a pair

    // Eg.2
    // bbaaaaabb
    //  ^^^^^^^^ bbaaaa(a + b) ---> bbaaaa
    // ^  ^^^^^^ bbaaa(a + b) ---> bbaaa

    res := 0
    N := len(s)
    i := N - 1
    Q := []byte{}
    for i > -1 {
        if len(Q) > 0 && Q[len(Q) - 1] == 'a' && s[i] == 'b' {
            Q = Q[:len(Q) - 1]
            res++
        } else {
            Q = append(Q, s[i])
        }
        i--
    }
    return res
}
