class Solution:

    def climbStairs(self, n: int) -> int:
        return [
            self.Solution_no_extra_space,
            self.Solution_Bottom_Up_of_n,
            self.Solution_Bottom_Up_of_n_plus_one,
            self.Solution_Topdown_recursive,
        ][ random.randint(0,3) ]( n )
        # 0-0
        # 1-1
        # 2-2
        # 3-3
        # 4-5 (*)

    # (0) - most efficient
    #   complexity: O(n) time, O(1) space
    # traverse from 3 to n, tracking the fibonacci number

    def Solution_no_extra_space(self, n):
        print('/Solution_no_extra_space')
        if n < 4:
            return n
        prevprev = 2
        prev = 3
        res = None
        for i in range(3, n):
            res = prev + prevprev
            prevprev = prev
            prev = res
        return res

    # (1) - classic top-down approach
    #   complexity: O(2 ** n) time, O(n) space
    # kind of like recursively tracking fibonacci numbers, 
    # we break each level/stair into 2 sub-problems: 
    #   1. its previous level 
    #   2. the 'previous-previous' level

    def Solution_Topdown_recursive(self, n):
        print('/Solution_Topdown_recursive')
        if n < 4:
            return n
        def topdown(E, n):
            if n < 4:
                return n
            if E[n] != -1:
                return E[n]
            E[n] = topdown(E, n - 1) + topdown(E, n - 2)
            return E[n]
        return topdown([-1] * (n + 1), n)

    # (2) - bottom-up approach:
    #   complexity: O(n) time, O(n) space
    #   here we build a DP array of size N
    #   each [index] has the value of `index + 1`
    #   (this is slightly different way from a classic bottom-up, cf. below)

    def Solution_Bottom_Up_of_n(self, n):
        print('/Solution_Bottom_Up_of_n')
        if n < 4:
            return n
        E = [i + 1 for i in range(n)]
        for i in range(3, n):
            E[i] = E[i - 1] + E[i - 2]
        return E[n - 1]

    # (3) - classic bottom-up approach:
    #   complexity: O(n) time, O(n) space
    #   here DP array is of N-size, filled with 0's
    #   then we filled it slot-by-slot up to the `n+1` slot

    def Solution_Bottom_Up_of_n_plus_one(self, n: int) -> int:
        print('/Solution_Bottom_Up_of_n_plus_one')
        if n < 4:
            return n
        E = [0] * (1 + n)
        E[1] = 1
        E[2] = 2
        for i in range(3, n + 1):
            E[i] = E[i - 1] + E[i - 2]
        return E[n]

