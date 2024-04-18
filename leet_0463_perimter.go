func islandPerimeter(grid [][]int) int {

    Solutions := []func([][]int) int {
        // Bruteforce_iterative,
        // Bruteforce_recursive,
        Math,
    }
    return Solutions[0](grid)
}

func Math(G [][]int) int {

    res := 0
    for r, row := range G {
        for c, cell := range row {
            if cell == 1 {
                initial := 4
                if r > 0 && G[r - 1][c] == 1 {
                    initial -= 2
                }
                if c > 0 && G[r][c - 1] == 1 {
                    initial -= 2
                }
                res += initial
            }
        }
    }
    return res
}

func Bruteforce_recursive(G [][]int) int {

    R := len(G)
    C := len(G[0])
    res := 0
    var hasOneNeig func([][]int, int, int) int
    hasOneNeig = func(G [][]int, r int, c int) int {
        if (r == R || r < 0 || c == C || c < 0 || G[r][c] == 0) {
            return 0
        }
        return 1
    }
    var countNeigs func([][]int, int, int) int
    countNeigs = func(G [][]int, r int, c int) int {
        neigs := hasOneNeig(G, r - 1, c) + hasOneNeig(G, r + 1, c) + hasOneNeig(G, r, c - 1) + hasOneNeig(G, r, c + 1)
        return 4 - neigs
    }
    for r, row := range G {
        for c, cell := range row {
            if cell == 1 {
                res += countNeigs(G, r, c)
            }
        }
    }
    return res
}

func Bruteforce_iterative(G [][]int) int {

    dr := []int {1, 0, -1, 0}
    dc := []int {0, 1, 0, -1}
    R := len(G)
    C := len(G[0])
    res := 0
    for r, row := range G {
        for c, cell := range row {
            if cell == 1 {
                i := 0
                for i < 4 {
                    rr, cc := r + dr[i], c + dc[i]
                    if (rr == R || rr < 0 || cc == C || cc < 0 || G[rr][cc] == 0) {
                        res += 1
                    }
                    i++
                }
            }
        }
    }
    return res
}
