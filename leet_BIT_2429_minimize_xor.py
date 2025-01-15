class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        # print(num1,bin(num1),num1.bit_count())
        # print(num2,bin(num2),num2.bit_count())
        bits = num2.bit_count()
        x = 0
        for pos in range(31, -1, -1):
            if num1 & 1 << pos and bits > 0 or bits > pos:
                bits -= 1
                x |= (1 << pos)
                print(bin(x),'pos/',pos)
            # if current bit pos. is on ie. 1, we'll have to use this 1
            #   ---> use up one bits, turn on same bit on X
            # otherwise we need to see if we have too much bits yet used:
            #   ---> pos === how many possible ie. 0 slots for 1's
            #   ---> bits === how many 1's we must put in
            #       - if we still must put in 'bits' bits
            #       - and we have 'pos' positions left
            #       ---> then we put in a 1 greedily
        return x



