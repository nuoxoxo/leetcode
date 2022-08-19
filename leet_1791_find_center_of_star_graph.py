class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        r = [ edges[0][0], edges[0][1] ]
        if edges[1][0] in r:
            return edges[1][0]
        return edges[1][1]
