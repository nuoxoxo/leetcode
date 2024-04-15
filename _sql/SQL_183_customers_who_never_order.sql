# Write your MySQL query statement below

SELECT  name        AS  Customers
FROM    Customers   AS  c
WHERE NOT EXISTS    (
    SELECT  customerID
    FROM    Orders
    WHERE   customerID = c.id
)   
