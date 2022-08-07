class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        res = 0
        diff = []
        for a, b in costs:
            diff.append([a - b, a, b]);
        diff.sort()
        half = len(diff) // 2
        for i in range(half):
            res += diff[i][1] + diff[i + half][2]
        return res 
