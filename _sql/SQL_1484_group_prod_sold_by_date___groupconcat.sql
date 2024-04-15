# Write your MySQL query statement below

select
    sell_date,
    count(distinct product) num_sold,
    group_concat(distinct product) products
from
    activities
group by
    1
