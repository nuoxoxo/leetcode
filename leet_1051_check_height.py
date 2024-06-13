class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        return [
            Oneliner,
            # Initial_solutions
        ][0](heights)

def Oneliner(heights: List[int]) -> int:
    return sum(l != r for l, r in zip(heights, sorted(heights)))

def Initial_solution(heights: List[int]) -> int:
    res = 0
    for l,r in zip(heights, sorted(heights)):
        if l != r: res += 1
    return res
