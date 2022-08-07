class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        diff = sorted(costs, key = lambda x: x[0] - x[1])
        half = len(costs) // 2
        res = 0
        for i in range(half):
            res += diff[i][0] + diff[i + half][1]
        return res 
