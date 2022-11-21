func floodFill(image [][]int, x int, y int, nc int) [][]int {
    if image[x][y] == nc {
        return image
    }
    oc := image[x][y]
    c := len(image[0])
    r := len(image)
    filled := make([][] bool, r)
    for i := range filled {
        filled[i] = make([] bool, c)
    }
    // fmt.Println(filled) // debugger
    DFS(image, filled, x, y, oc, nc)
    return image
}

func DFS(image [][] int, filled [][] bool, x int, y int, oc int, nc int) {
    r := len(image)
    c := len(image[0])
    if x < 0 || y < 0 || x > r - 1 || y > c - 1 || image[x][y] != oc || filled[x][y] {
        return
    }
    filled[x][y] = true
    image[x][y] = nc
    DFS(image, filled, x + 1, y, oc, nc)
    DFS(image, filled, x - 1, y, oc, nc)
    DFS(image, filled, x, y + 1, oc, nc)
    DFS(image, filled, x, y - 1, oc, nc)
}
