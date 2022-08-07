/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} newColor
 * @return {number[][]}
 */
var floodFill = function(image, x, y, newColor) {
    let oldColor = image[x][y]
    if (oldColor == newColor)
        return image
    let c = image[0].length
    let r = image.length
    image[x][y] = newColor
    if (x < r - 1)
        floodFill(image, x + 1, y, newColor)
    if (x > 0)
        floodFill(image, x - 1, y, newColor)
    if (y < c - 1)
        floodFill(image, x, y + 1, newColor)
    if (y > 0)
        floodFill(image, x, y - 1, newColor)
    return image
};
