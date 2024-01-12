class Solution:
    def halvesAreAlike(self, s: str) -> bool:

        def Solution_2pass (s: str, charset: list) -> int:
            res = 0
            mid = len(s) // 2
            for i in range(mid):
                if s[i] in charset: res += 1
                if s[mid + i] in charset: res -= 1
            return res == 0

        def Solution_cmp_length (s: str, charset: list) -> int:
            return len([_ for _ in list(s[:len(s)//2]) if _ in charset])\
                == len([_ for _ in list(s[len(s)//2:]) if _ in charset])

        charset = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        n = random.randint(0, 1)
        print([ 'Solution_2pass', 'Solution_cmp_length' ][ n ])

        return [Solution_2pass, Solution_cmp_length][ n ](s, charset)
