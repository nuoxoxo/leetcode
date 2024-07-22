func lexicalOrder(n int) []int {

    Solutions := []func(int)[]int{
        // DFS,
        Iterative,
    }
    return Solutions[0](n)
}

func Iterative(n int) []int {

    res := []int{}
    curr := 1
    i := 0
    for i < n {
        res = append(res, curr)
        if curr <= n {
            curr = curr * 10
        }
        if curr > n {
            curr = curr / 10
            if curr == n {
                curr = curr / 10
            }
            curr += 1
            for curr % 10 == 0 {
                curr = curr / 10
            }
        }
        i++
    }
    return res
}

func DFS(n int) []int {

    res := []int{}
    END := 10;
    if END > n + 1 {
        END = n + 1
    }
    var dfs func(int)
    dfs = func(curr int) {
        if curr > n {
            return
        }
        res = append(res, curr)
        i := 0
        for i < END {
            dfs( curr * 10 + i )
            i++
        }
    }
    curr := 1
    for curr < END {
        dfs(curr)
        curr++
    }
    return res
}
