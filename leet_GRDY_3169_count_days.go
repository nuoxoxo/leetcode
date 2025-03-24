func countDays(days int, meetings [][]int) int {
    Solutions := []func(int,[][]int) int {
        Greedy,
    }
    return Solutions[0](days,meetings)
}

func Greedy(days int, meetings [][]int) int {
    sort.Slice(meetings, func(l,r int) bool {
        if meetings[l][0] == meetings[r][0] {
            return meetings[l][1] < meetings[r][1]
        }
        return meetings[l][0] < meetings[r][0]
    })
    ok := 0
    R := 0
    for _, lr := range meetings {
        l, r := lr[0], lr[1]
        l--
        if R < l { ok += l - R }
        if R < r { R = r }
    }
    return ok + days - R
}
