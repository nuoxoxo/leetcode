select
    max(a.salary) as SecondHighestSalary
    from employee as a
    join employee as b
    on a.salary < b.salary
