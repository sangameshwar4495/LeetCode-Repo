# Write your MySQL query statement below
SELECT Department, Employee, Salary
FROM
(SELECT d.name as Department, e.name as Employee, e.Salary as Salary,
    DENSE_RANK() OVER (
        PARTITION BY departmentId
        order by salary DESC
    ) as rk
FROM EMPLOYEE e
LEFT JOIN Department d
on departmentId=d.id
) pre
where rk<=3