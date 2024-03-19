func leastInterval(tasks []byte, n int) int {

    /*
    A A A B B B - n=2
    --->    A . . A . . A
    --->    A B . A B . A B     (8)

    A A A B B B - n=3
    --->    A . . . A . . . A
    --->    A B . . A B . . A B (10)_

    A A B B C D - n=1
    --->    A .    A
    --->    A B    A B
    --->    A B C  A B
    --->    A B C  A B D    (6)
    */

    D := make([]int, 26)
    for _, byt := range tasks {
        D[byt - 'A']++
    }
    sort.Slice(D, func (l, r int) bool {
        return D[l] > D[r]
    })
    segments := D[0] - 1
    mustcool := segments * n
    N := len(tasks)
    i := 1
    for i < 26 && D[i] > 0 {
        if D[i] < segments {
            mustcool -= D[i]
        } else {
            mustcool -= segments
        }
        i++
    }
    if mustcool < 0 {
        return N
    }
    return N + mustcool
}

