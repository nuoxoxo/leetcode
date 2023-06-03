/* Write your PL/SQL query statement below */

select id, case
    when p_id is null then 'Root'
    when id in (    -- not `else when`
        select p_id from Tree
    ) then 'Inner'
    else 'Leaf'
end as type from Tree
