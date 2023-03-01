/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} newColor
 * @return {number[][]}
 */

var floodFill = function(image, sr, sc, newColor) {
    let oldColor = image[sr][sc]
    let c = image[0].length
    let r = image.length
    let flooded = new Array(c)
    let i = -1
    while (++i < c){
        let tmp = new Array(r)
        tmp.fill(false)
        flooded[i] = tmp
    }
    DFS(image, flooded, sr, sc, oldColor, newColor)
    return image 
};

function DFS(image, flooded, x, y, oldColor, newColor) {
    let c = image[0].length
    let r = image.length

    if (x < 0 || y < 0 || x > r - 1 | y > c - 1 || 
        image[x][y] != oldColor || flooded[x][y])
        return

    image[x][y] = newColor
    flooded[x][y] = true
    DFS( image, flooded, x + 1, y, oldColor, newColor )
    DFS( image, flooded, x - 1, y, oldColor, newColor )
    DFS( image, flooded, x, y + 1, oldColor, newColor )
    DFS( image, flooded, x, y - 1, oldColor, newColor )
}
