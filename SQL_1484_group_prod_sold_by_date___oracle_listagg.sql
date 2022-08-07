/* Write your PL/SQL query statement below */

select
    to_char(sell_date,'YYYY-MM-DD') sell_date,
    count(distinct product) num_sold,
    listagg(product, ',') within group(order by product) products
from (
    select distinct *
    from activities
)
group by
    sell_date

