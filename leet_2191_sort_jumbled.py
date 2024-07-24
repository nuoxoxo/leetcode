class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        return [
            # Initial_soln,
            Sort_computed_vals,
        ][0](mapping, nums)

def Sort_computed_vals(mapping:List[int], nums:List[int]) -> List[int]:
    def f(n:int) -> int:
        if n == 0:
            return mapping[0]
        s = str(n)
        res = 0
        ten = 1
        while n > 0:
            res += mapping[n % 10] * ten
            n //= 10
            ten *= 10
        return res
    return sorted(nums, key = lambda _: f(_))

# [8,9,4,0,2,1,3,5,7,6]
#  0 1 2 3 4 5 6 7 8 9 (index)
# [991,338,38]

def Initial_soln(mapping:List[int], nums:List[int]) -> List[int]:

    todo = []
    for i, n in enumerate(nums):
        if n == 0:
            todo.append( mapping[0], i, n )
            continue
        s = str(n)
        res = ''
        for c in s:
            res += str(mapping[int(c)])
        todo.append( (int(res), i, n) )
    return [_[2] for _ in sorted(todo, key=lambda _: (_[0], _[1]))]


