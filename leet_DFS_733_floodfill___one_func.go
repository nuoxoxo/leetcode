func floodFill(image [][]int, x int, y int, nc int) [][]int {
    if image[x][y] == nc {
        return image
    }
    oc := image[x][y]
    c := len(image[0])
    r := len(image)
    image[x][y] = nc
    if x + 1 < r && image[x + 1][y] == oc {
        floodFill(image, x + 1, y, nc)
    }
    if x - 1 > -1 && image[x - 1][y] == oc {
        floodFill(image, x - 1, y, nc)
    }
    if y + 1 < c && image[x][y + 1] == oc {
        floodFill(image, x, y + 1, nc)
    }
    if y - 1 > -1 && image[x][y - 1] == oc {
        floodFill(image, x, y - 1, nc)
    }
    return image
}
