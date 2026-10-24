# Write your MySQL query statement below
SELECT IFNULL(
    (select DISTINCT salary as SecondHighestSalary FROM employee order by salary desc limit 1 offset 1), null
) as SecondHighestSalary 