/* Write your PL/SQL query statement below */

select id, 'Root' as type from Tree
where p_id is null

union

select id, 'Inner' as type from Tree
where id in (
    select p_id from Tree
)
and p_id is not null

union

select id, 'Leaf' as type from Tree
where id not in (
    select p_id from Tree
    where p_id is not null
) and p_id is not null

order by id

