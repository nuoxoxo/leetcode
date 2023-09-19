func findDuplicate(n []int) int {
    len := len(n)
    if len == 2 {
        return n[0]
    }
    sort.Ints(n)
    mid := len / 2
    i, j := 1, len-2
    for i != j && i < mid && j > mid {
        if n[i-1] == n[i] {
            return n[i]
        }
        if n[j] == n[j+1] {
            return n[j]
        }
        i++
        j--
    }
    return n[mid]
}
