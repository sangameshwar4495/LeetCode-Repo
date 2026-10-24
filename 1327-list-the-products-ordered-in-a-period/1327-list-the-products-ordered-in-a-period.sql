# Write your MySQL query statement below
SELECT p.product_name as product_name, SUM(unit) as unit
from orders o
left join products p
on p.product_id = o.product_id
WHERE MONTH(o.order_date)=2 and YEAR(o.order_date)=2020
GROUP by o.product_id
having unit>=100