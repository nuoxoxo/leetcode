class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        # formula/
        #   a ^ b = (a+b)%2
        # original/
        #   n0, n1, n2, n3, n4, ...nN-1, n0

        # derived/
        #   n0^n1, n1^n2, n2^n3, ...nN-1 ^ n0 <--- insight:
        #       we get 0 if we xor all of them 

        #   (n0+n1)%2, (n1+n2)%2, .... <--- more insight:
        #       the 1st insight is always true, so we also get 0
        #       if we xor all elems in this converted (w/ %) line,
        #       and for (A % 2)^(B % 2)^(C % 2)^... to be 0
        #       A,B,C,.... must all be even
        #       so, n0+n1,n1+n2,n2+n3,... must all be even, and their sum is even
        return 0 == sum(derived) % 2
