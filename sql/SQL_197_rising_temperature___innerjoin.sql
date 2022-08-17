# Write your MySQL query statement below

select
    w2.id 
from
    weather w1
INNER JOIN
    weather w2
where
    DATEDIFF(w2.recordDate, w1.recordDate) = 1 
AND 
    w2.temperature > w1.temperature;

