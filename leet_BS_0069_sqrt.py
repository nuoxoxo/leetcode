class Solution:
    def mySqrt(self, x: int) -> int:
        return [
            self.Solution_Newton,
            self.Solution_brute_force,
            self.Solution_binary_search,
            # self.Solution_bruteforce_46340,
        ][ random.randint( 0,2 ) ]( x )

    def Solution_binary_search(self, x):
        print('/Solution_binary_search')
        L, R = 0, x
        res = L
        while L <= R:
            mid = (R - L) // 2 + L
            sq = mid * mid
            if sq == x:
                return mid
            if sq > x:
                R = mid - 1
            else:
                res = mid
                L = mid + 1
        return res

    def Solution_Newton(self, x):
        print('/Solution_Newton')
        if x == 0:
            return 0
        res = x
        while res ** 2 > x:
            res = (res + x // res) // 2
        return res

    def Solution_brute_force(self, x):
        print('/Solution_brute_force')
        if x == 0:
            return 0
        res = 1
        while res ** 2 <= x and (res + 1) ** 2 <= x:
            res += 1
        return res

    # Misc. solution (deprecated)
    def Solution_bruteforce_46340(self, x):
        print('\Solution_bruteforce_46340')
        res = 1
        # >>> 46340 ** 2
        # 2147395600
        while res * res <= x and res <= 46340:
            if res ** 2 == x:
                return res
            res += 1
        return res - 1 
