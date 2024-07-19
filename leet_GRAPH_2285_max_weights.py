class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:

        # [0,1],[1,2],[2,3],[0,2],[1,3],[2,4] -> extract a list of degress
        # 0 -> 1,2 -> degree: 2
        # 1 -> 0,2,3 -> d: 3
        # 2 -> 0,1,3,4 -> d: 4
        # 3 -> d: 2
        # 5 -> d: 1
        # [2, 3, 4, 2, 1]
        #
        #   - assign each city w/ a value 1 to n
        #   - where each value can only be used once
        #   - The importance of a road = sum of the values of the two cities it connects
        # in order to achieve optimal importance, we sort the degree-list reversedly
        #   [4, 3, 2, 2, 1]
        # assign value by its index plus 1
        #   4*5 + 3*4 + 2*3 + 2*2 + 1*1
        #   ^ ^   ^ ^
        #   i n   i n+1  ...
        #   res = 20+12+6+4+1 = 43 correct

        Way2reverse = True # 2 ways
        degrees = [0] * n
        for a, b in roads:
            degrees[a] += 1
            degrees[b] += 1
        res = 0
        ### way 2
        if Way2reverse:
            degrees.sort()
            for idx, d in enumerate(degrees):
                res += (idx + 1) * d
            return res
        ### initial soln
        degrees.sort(reverse=True)
        for idx, d in enumerate(degrees):
            res += (n - idx) * d
        return res
