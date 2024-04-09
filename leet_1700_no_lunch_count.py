class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        res = 0
        students = deque(students)
        sandwiches = deque(sandwiches)
        while res < len(students):
            if students[0] == sandwiches[0]:
                students.popleft()
                sandwiches.popleft()
                res = 0
            else:
                students.append(students.popleft())
                res += 1
        return len(students)
