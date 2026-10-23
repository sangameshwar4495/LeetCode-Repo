# Write your MySQL query statement below
with daily as (
    select visited_on, SUM(amount) as amount
    FROM Customer
    group by visited_on
), moving as (
    select visited_on, 
        SUM(amount) over (
            order by visited_on
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS amount,
        ROW_NUMBER() over(
            order by visited_on
        ) as rn
    from daily
)

select visited_on, amount, ROUND(amount/7, 2) as average_amount
FROM moving
where rn>=7