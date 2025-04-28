func checkValidCuts(n int, rectangles [][]int) bool {
    Solutions := []func([][]int) bool {
        Twopass,
    }
    return Solutions[0](rectangles) // discarded n
}

func Twopass(rectangles [][]int) bool {

    hori,vert := [][]int{}, [][]int{}
    for _,q := range rectangles {
        a,b,c,d := q[0],q[1],q[2],q[3]
        hori = append(hori,[]int{a,c})
        vert = append(vert,[]int{b,d})
    }

    var f func(rec[][]int)bool
    f = func(rec[][]int)bool {
        sort.Slice(rec, func(l,r int) bool {
            if rec[l][0] == rec[r][0] { return rec[l][1] < rec[r][1] }
            return rec[l][0] < rec[r][0]
        })
        ok := 0
        R := rec[0][1]
        for _,lr := range rec {
            l,r := lr[0],lr[1]
            if R <= l {
                ok += 1
                if ok > 1 { return true }
            }
            if R < r { R = r }
        }
        return false
    }
    return f(hori) || f(vert)
}
