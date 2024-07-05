/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nodesBetweenCriticalPoints(head *ListNode) []int {
    solutions := []func(*ListNode) []int {
        // Initial_solution,
        Try_to_be_smarter,
    }
    return solutions[0](head)
}

func Try_to_be_smarter(head * ListNode) []int {

    prev := head.Val
    var left int
    var lastSeen int
    gotLeft := false
    mx := -2147483648
    mn := 2147483647
    curr := head
    _next := head.Next
    if _next == nil {
        return []int{ -1, -1 }
    }
    index := 2
    for _next.Next != nil {
        curr = curr.Next
        _next = _next.Next
        if (prev < curr.Val && curr.Val > _next.Val) || (prev > curr.Val && curr.Val < _next.Val) {
            if gotLeft {
                if mn > index - lastSeen {
                    mn = index - lastSeen
                }
                if mx < index - left {
                    mx = index - left
                }
            } else {
                gotLeft = true
                left = index
            }
            lastSeen = index
        }
        prev = curr.Val
        index++
        
    }
    if mx == -2147483648 || mn == 2147483647 {
        return []int{-1, -1}
    }
    return []int{ mn, mx }
}

// o --- o --- o --- o --- o
// prev  ^     ^
//       curr  _nxt

func Initial_solution(head * ListNode) []int {

    dis := []int{}
    prev := head.Val
    curr := head
    _next := head.Next
    if _next == nil {
        return []int{-1, -1}
    }
    index := 2
    for _next.Next != nil {
        curr = curr.Next
        _next = _next.Next
        if (prev < curr.Val && curr.Val > _next.Val) || (prev > curr.Val && curr.Val < _next.Val) {
            dis = append(dis, index)
        }
        prev = curr.Val
        index++
    }
    N := len(dis)
    if N < 2 {
        return []int{-1, -1}
    }
    sort.Ints(dis)
    mn := 2147483647
    i := 1
    for i < N {
        d := dis[i] - dis[i - 1]
        if mn > d {
            mn = d
        }
        i++
    }
    return []int{ mn, dis[N - 1] - dis[0] }
}

