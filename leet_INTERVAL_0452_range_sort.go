func findMinArrowShots(points [][]int) int {

    Solutions := []func(points [][]int) int {
        Update_only_running_end,
        // Update_both_ends,
    }
    return Solutions[0](points)
}

func Update_only_running_end(points [][]int) int {
    sort.Slice(points, func(i int, j int) bool { return points[i][0] < points[j][0] })
    runningE := points[0][1]
    res := 1
    i := 1
    for i < len(points) {
        newS, newE := points[i][0], points[i][1]
        if newS <= runningE {
            if newE < runningE {
                runningE = newE
            }
        } else {
            runningE = newE
            res++
        }
        i++
    }
    return res
}

func Update_both_ends(points [][]int) int {
    sort.Slice(points, func(i int, j int) bool { return points[i][0] < points[j][0] })
    runningS, runningE := points[0][0], points[0][1]
    res := 1
    i := 1
    for i < len(points) {
        newS, newE := points[i][0], points[i][1]
        if newS <= runningE {
            if newE < runningE {
                runningE = newE
            }
            if newS > runningS {
                runningS = newS
            }
        } else {
            runningS, runningE = newS, newE
            res++
        }
        i++
    }
    return res
}
