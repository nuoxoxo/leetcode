/* Write your PL/SQL query statement below */

select
    employee_id
from
    employees
full outer join
    salaries using(employee_id)
where
    name is null or salary is null
order by
    employee_id
