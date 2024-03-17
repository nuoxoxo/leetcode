func insert(intervals [][]int, newInterval []int) [][]int {
    res := [][]int{}
    for _, inter := range intervals {

        newS, newE := newInterval[0], newInterval[1]
        s, e := inter[0], inter[1]

        if newS > e {
            // condition //1 - [currInter], [newInter]
            //   ---> just accept the newInter
            res = append(res, inter)
            // condition //2 - [newInter], [currInter]
            //   ---> accept newInter, replace newInter w/ currInter 
        } else if newE < s {
            res = append(res, newInterval)
            newInterval = inter
        } else if newS <= e || newE >= s {
            // condition //3 - overlapped
            //   ---> update newInter
            //
            //   S--  E  |   S--E    | S  --E
            // s  --e    | s  --  e  |   s--  e
            // 
            newInterval[0] = s
            if newS < s {
                newInterval[0] = newS
            }
            newInterval[1] = e
            if newE > e {
                newInterval[1] = newE
            }
        }
    }
    res = append(res, newInterval)
    return res
}

