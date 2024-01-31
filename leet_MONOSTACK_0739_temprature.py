class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        return [
            # self.Monotonic_stack_backward,
            self.Monotonic_stack_forward,
        ][ random.randint(0,0) ]( temperatures )

    def Monotonic_stack_forward(self, t):
        D = []
        res = [0] * len(t)
        for i in range(len(t)):
            while D and t[i] > t[D[-1]]:
                res[D[-1]] = i - D[-1]
                D.pop()
            D.append(i)
        return res

    def Monotonic_stack_backward(self, t: List[int]) -> List[int]:
        D = []
        res = [0] * len(t)
        for i in range(len(t) - 1, -1, -1):
            # print(D)
            while D and t[i] >= t[D[-1]]:
                D.pop()
            if D:
                res[i] = D[-1] - i
            D.append(i)
            # print(D,'\n')
        return res

