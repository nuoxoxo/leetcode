# Write your MySQL query statement below

with temp as (
    select      e.employee_id, e.name, s.salary
    from        Employees as e
    left join   Salaries as s
    on          e.employee_id = s.employee_id
    union
    select      s.employee_id, e.name, s.salary
    from        Salaries as s
    left join   Employees as e
    on          e.employee_id = s.employee_id
)

select      employee_id
from        temp
where       name is null or salary is null
order by    employee_id
