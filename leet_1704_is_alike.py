class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        charset = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        def Solution_2pass (s: str, charset: list) -> int:
            res = 0
            mid = len(s) // 2
            for i in range(mid):
                if s[i] in charset: res += 1
                if s[mid + i] in charset: res -= 1
            return res == 0
        def Solution_list_comprehension (s: str, charset: list) -> int:
            return len([_ for _ in list(s[:len(s)//2]) if _ in charset])\
                == len([_ for _ in list(s[len(s)//2:]) if _ in charset])

        n = random.randint(0, 1)
        print([ 'Solution_2pass', 'Solution_list_comprehension' ][ n ])

        return [Solution_2pass, Solution_list_comprehension][ n ](s, charset)
