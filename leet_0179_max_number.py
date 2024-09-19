class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        return [
            using_cmp_to_key,
            # mult9,
        ][0](nums)

def using_cmp_to_key(nums: List[int]) -> str:
    def cmp(a: int, b: int) -> str:
        l, r = str(a), str(b)
        return int(r + l) - int(l + r)
    S = [str(_) for _ in nums]
    res = ''.join(sorted(S, key=cmp_to_key(cmp)))
    N = len(res)
    i = 0
    while i < N and res[i] == '0':
        i += 1
    if i == N:
        return "0"
    return res

def mult9(nums: List[int]) -> str:
    S = [str(n) for n in nums]
    S.sort(key=lambda x: x * 9, reverse=True)
    # compare strings as if they were concatenated 9 times
    # in order to ensure correct ordering w/ numbers with diff lengths 
    # eg. 30, 3
    # print(S)
    res = ''.join(S)
    i = 0
    while i < len(res) and res[i] == '0':
        i += 1
    if i == len(res):
        return "0"
    return res
