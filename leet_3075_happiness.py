class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        return [
            # Popped_sorted_list,
            Constant_space,
        ][0](happiness, k)

def Constant_space(happiness: List[int], k: int) -> int:
    happiness.sort()
    i = len(happiness) - 1
    minus = 0
    res = 0
    while k > 0:
        temp = happiness[i] - minus
        if temp < 1:
            return res
        res += temp
        minus += 1
        k -= 1
        i -= 1
    return res

def Popped_sorted_list(happiness: List[int], k: int) -> int:
    happiness.sort()
    res = 0
    minus = 0
    while k > 0:
        n = happiness.pop() - minus
        if n < 1:
            return res
        res += n
        minus += 1
        k -= 1
    return res

