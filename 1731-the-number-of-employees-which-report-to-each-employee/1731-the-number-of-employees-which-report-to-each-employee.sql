# Write your MySQL query statement below
select distinct e1.reports_to as employee_id, e2.name as name, count(*) as reports_count, ROUND(avg(e1.age),0) as average_age
from employees e1
left join employees e2
on e1.reports_to = e2.employee_id
where e1.reports_to is not null
group by e1.reports_to
order by e1.reports_to