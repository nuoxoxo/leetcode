#* ******************************************** *#
#*                                              *#
#*              \\             /`/``            *#
#*              ~\o o_       0 0\               *#
#*              / \__)      (u  ); _  _         *#
#*       / \/ \/  /           \  \/ \/ \        *#
#*      /(   . . )            (         )\      *#
#*     /  \_____/              \_______/  \     *#
#*         []  []               [[] [[]    *.   *#
#*         []] []]              [[] [[]         *#
#*                                              *#
#* ************************************ nuo *** *#

class Solution:
    
    def floodFill(self, image: List[List[int]], \
        i: int, j: int, newColor: int) -> List[List[int]]:
        
        if newColor == image[i][j]:
            return image
        
        oldColor = image[i][j]
        R, C = len(image), len(image[0])
        
        def DFS(i, j):
            if -1 < i < R and -1 < j < C and image[i][j] == oldColor:
                image[i][j] = newColor
                DFS(i + 1, j)
                DFS(i - 1, j)
                DFS(i, j + 1)
                DFS(i, j - 1)
        DFS(i, j)
        return image 
