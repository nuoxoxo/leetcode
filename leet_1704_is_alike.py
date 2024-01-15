class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n = random.randint(0, 1)
        print(n)
        return [
            self.Solution_2pass,
            self.Solution_list_comprehension\
        ][ n ](s)

    def Solution_2pass (self, s: str) -> bool:
        print('/Solution_2pass')
        charset = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        res = 0
        mid = len(s) // 2
        for i in range(mid):
            if s[i] in charset: res += 1
            if s[mid + i] in charset: res -= 1
        return res == 0

    def Solution_list_comprehension (self, s: str) -> bool:
        print('/Solution_list_comprehension')
        charset = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        return len([_ for _ in list(s[:len(s)//2]) if _ in charset])\
            == len([_ for _ in list(s[len(s)//2:]) if _ in charset])

    
