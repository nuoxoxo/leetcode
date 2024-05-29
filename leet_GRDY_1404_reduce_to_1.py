class Solution:
    def numSteps(self, s: str) -> int:
        return [
            Greedy_backwards,
            # Unabashedly_bigint,
        ][0](s)

def Greedy_backwards(s:str) -> int:

    res, carry = 0, 0
    # `carry` must be in [0, 1]

    for i in range(len(s) - 1, 0, -1):

        # operation by 2 `//= 2` is always performed
        # regardless of the digit being ODD or EVEN
        res += 1

        dig = ord(s[i]) - ord('0') + carry
        carry = dig // 2
        dig %= 2
        
        # if `digit` is 1, we +1 to carry, also +1 steps
        if dig == 1:
            res += 1
            carry += 1
        
    res += carry
    return res


def Unabashedly_bigint(s:str) -> int:
    n = int(s, 2)
    res = 0
    while True:
        if n == 1:
            break
        res += 1
        if n % 2 == 1:
            n += 1
        else:
            n >>= 1
    return res

