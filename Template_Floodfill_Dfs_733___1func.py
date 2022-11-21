class Solution:
    def floodFill(self, image: List[List[int]], i: int, j: int, new_color: int) -> List[List[int]]:

        if image[i][j] is new_color:
            return image

        old_color = image[i][j]
        C = len(image[0])
        R = len(image)

        image[i][j] = new_color

        if (i < R - 1 and image[i + 1][j] == old_color):
            self.floodFill(image, i + 1, j, new_color);

        if (i > 0 and image[i - 1][j] is old_color):
            self.floodFill(image, i - 1, j, new_color);

        if (j < C - 1 and image[i][j + 1] is old_color):
            self.floodFill(image, i, j + 1, new_color);

        if (j > 0 and image[i][j - 1] is old_color):
            self.floodFill(image, i, j - 1, new_color);
            
        return image
