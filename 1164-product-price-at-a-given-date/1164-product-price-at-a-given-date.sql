# Write your MySQL query statement below
select distinct p.product_id, COALESCE(a.price,10) AS price
from products p
left join 
(   SELECT product_id, new_price as price
    FROM (
            select *, ROW_NUMBER() OVER (
                PARTITION BY product_id
                order by change_date Desc
            ) as rn
            from Products
            WHERE change_date<='2019-08-16'
        ) l
    where rn=1
) a
on p.product_id = a.product_id
