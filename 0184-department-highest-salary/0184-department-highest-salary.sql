# Write your MySQL query statement below
with cte as (
    select *, RANK() over (
        partition by departmentId
        order by salary desc
    ) as rn
    from employee
    
)

select d.name as Department , e.name as Employee , e.salary as Salary
from cte e
left join department d
on d.id = e.departmentId
where e.rn=1 
