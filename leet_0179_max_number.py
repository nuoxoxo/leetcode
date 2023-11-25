class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        S = [str(n) for n in nums]
        S.sort(key=lambda x: x * 9, reverse=True)
        # compare strings as if they were concatenated 9 times
        # in order to ensure correct ordering w/ numbers with diff lengths 
        # eg. 30, 3
        res = ''.join(S)
        i = 0
        while i < len(res) and res[i] == '0':
            i += 1
        if i == len(res):
            return "0"
        return res
