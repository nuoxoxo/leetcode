func maxUniqueSplit(s string) int {
    solutions := []func(string)int{
        Backtracking,
    }
    return solutions[0]( s )
}

func Backtracking(s string) int {

    N := len(s)
    SEEN := make(map[string]bool)
    // var backtrack func(int)int = func(left int)int{
    // 👆 wrong bc. we have to pre-declare the func
    //  in order to recurse
    var backtrack func(int)int
    backtrack = func(left int) int {
        if left == N { return 0 }
        res := -1
        right := left
        for right < N {
            right++
            sub := s[left : right]
            if SEEN[sub] { continue }
            SEEN[sub] = true
            next := backtrack(right)
            if res < next + 1 {
                res = next + 1
            }
            SEEN[sub] = false
        }
        return res
    }
    return backtrack(0)
}
