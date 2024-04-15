# Write your MySQL query statement below

SELECT
    w1.id
FROM
    weather w1
INNER JOIN
    weather w2
WHERE
    to_days(w1.RecordDate) = to_days(w2.RecordDate) + 1
AND
    w1.Temperature > w2.Temperature;
