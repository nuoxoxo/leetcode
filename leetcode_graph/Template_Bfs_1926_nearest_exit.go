func nearestExit(maze [][]byte, entrance []int) int {
    C := len(maze[0])
    R := len(maze)
    dir := [][] int { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }

    // D := make([][] int) // missing the len arg
    D := make([][] int, 0)

    // D = append(D, [] int {entrance[0], entrance[1]} )
    D = append(D, [] int {entrance[0], entrance[1], 0} )

    maze[entrance[0]][entrance[1]] = '+'
    res := 1
    for len(D) != 0 {
        n := len(D)
        for n != 0 {
            temp_x := D[0][0]
            temp_y := D[0][1]
            D = D[1:]
            for _, d := range dir {
                x := temp_x + d[0]
                y := temp_y + d[1]
                if x < R && x > -1 && y < C && y > -1 && maze[x][y] == '.' {
                    if x == 0 || y == 0 || x == R - 1 || y == C - 1 {
                        return res
                    } else {
                        maze[x][y] = '+'
                        D = append(D, [] int {x, y})
                        // D = append(D, {x, y})
                    }
                }
            }
            n--
        }
        res++
    }
    return -1
}
