class Solution:
    def average(self, salary: List[int]) -> float:
        # way 1
        """
        hi = max(salary)
        lo = min(salary)
        a = []
        for n in salary:
            if n not in (lo, hi):
                a.append(n)
        return sum(a) / len(a)
        """

        # way 2
        return (sum(salary) - max(salary) - min(salary)) / (len(salary) - 2)
