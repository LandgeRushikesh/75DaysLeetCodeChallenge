# Write your MySQL query statement below
SELECT e.name,b.bonus
FROM Employee e
LEFT OUTER JOIN Bonus b
ON e.empID = b.empID
WHERE b.bonus<1000 || b.bonus IS NULL;