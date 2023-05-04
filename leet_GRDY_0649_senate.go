func predictPartyVictory(senate string) string {
    r := []int {}
    d := []int {}
    idx := len(senate)
    for i, c := range senate {
        if c == 'R' {
            r = append(r, i)
        } else {
            d = append(d, i)
        }
    }
    for len(r) != 0 && len(d) != 0 {
        rr := r[0]
        dd := d[0]
        r = r[1:]
        d = d[1:]
        if rr < dd {
            r = append(r, idx)
        } else {
            d = append(d, idx)
        }
        idx++
    }
    if len(r) > 0 {
        return "Radiant"
    }
    return "Dire"
}
