class Solution:
    def numberOfSteps(self, num: int) -> int:
        return bin(num).count('1') * 2 + bin(num).count('0') - 2
