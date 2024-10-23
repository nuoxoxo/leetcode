func dividePlayers(skill []int) int64 {
    sort.Ints(skill)
    l, r := 0, len(skill) - 1
    expected := skill[l] + skill[r]
    var res int64 = int64(skill[l] * skill[r])
    l++
    r--
    for l < r {
        if expected != skill[l] + skill[r] { return -1 }
        res += int64(skill[l] * skill[r])
        l++
        r--
    }
    return res
}
