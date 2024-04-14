func maximalRectangle(matrix [][]byte) int {

    // if len(matrix) == 0 || len(matrix[0]) == 0 {
    //     return 0
    // }    
    res := 0
    R, C := len(matrix), len(matrix[0])
    // cumulative sums for each col up to the current row
    SUMS := make([][]int, R + 1)

    /*
    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0

    cumulative sums
    0 0 0 0 0
    1 0 1 0 0
    2 0 2 1 1
    3 1 3 2 2
    4 1 3 3 2
    */

    for r, _ := range SUMS {
        SUMS[r] = make([]int, C)
    }
    r := 1
    var c int
    for r < R + 1 {
        c = 0
        for c < C {
            if matrix[r - 1][c] == '1' {
                SUMS[r][c] = SUMS[r - 1][c] + 1
            }
            c++
        }
        r++
    }
    
    All_ones := func(upper, lower, c int) bool {

        // check if:
        //  within a column range from upper to lower are '1's
        //  ---> we have all '1's if the Sum == Number of rows in-btw
        slots := lower - upper + 1
        return slots == SUMS[lower + 1][c] - SUMS[upper][c]
    }

    top := 0
    var btm int
    for top < R {
        btm = 0
        for btm < R {
            cols := 0
            c = 0
            for c < C {
                if All_ones(top, btm, c) {
                    cols++
                } else {
                    cols = 0
                }
                rows := btm - top + 1
                area := rows * cols
                if res < area {
                    res = area
                }
                c++
            }
            btm++
        }
        top++
    }
    return res
}

