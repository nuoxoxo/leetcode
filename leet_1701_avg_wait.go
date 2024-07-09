func averageWaitingTime(customers [][]int) float64 {

    Solutions := []func([][]int) float64 {
        // My_simulation,
        My_simplified,
    }
    return Solutions[0](customers)
}

func My_simplified(customers [][]int) float64 {

    N := len(customers)
    W := 0.0
    elapse := float64(customers[0][0])
    for _, p := range customers {
        arrive := float64(p[0])
        prepare := float64(p[1])
        if elapse < arrive {
            elapse = arrive
        }
        W += elapse - arrive + prepare
        elapse += prepare
    }
    return W / float64(N)
}

func My_simulation(customers [][]int) float64 {

    N := len(customers)
    W := 0.0
    elapse := float64(customers[0][0])
    for _, p := range customers {
        arrive := float64(p[0])
        prepare := float64(p[1])
        var overlap float64
        if elapse <= arrive {
            W += prepare
            elapse = arrive + prepare
            fmt.Printf("elp/ %f wait/ %f\n", elapse, prepare)
        } else {
            overlap = elapse - arrive
            W += overlap + prepare
            elapse += prepare
            fmt.Printf("elp/ %f olp/ %f wait/ %f\n", elapse, overlap, prepare)
        }
    }
    return W / float64(N)
}

