func maxProfitAssignment(difficulty []int, profit []int, worker []int) int {
    
    /*
    // IDEA: for each worker, assign a job of max profit

    // eg.1
    work(ers): 4,5,6,7
    level:  2, 4, 6, 8,10
    money: 10,20,30,40,50
                ^ money-20 job with level-4 difficulty 
                    is the best for capacity-4 and capacity-6
                    ^ money-30 job with level-6 diffculty
                        worker-6 and worker-7 can take this job
    ---> res = 20 * 2 + 30 * 2

    // eg.2
    work(ers): 40,25,25
    level:    85,47,57
    money:    24,66,99
    ---> res=0 (every difficulty level exceeds anyone's capacity)
    */
    
    // N := len(difficulty)
    // if N != len(profit) { fmt.Println("wtf/") }
    Q := [][]int{}
    for i, d := range difficulty {
        Q = append(Q, []int{d, profit[i]})
    }
    sort.Slice(Q, func(L, R int) bool {
        return Q[L][0] < Q[R][0]
    })
    sort.Ints(worker)
    res := 0
    curr := 0
    for _, hp := range worker {
        for len(Q) != 0 && hp >= Q[0][0] {
            money := Q[0][1]
            if curr < money {
                curr = money
            }
            Q = Q[1:]
        }
        res += curr
    }
    return res
}
