select customer_id, count(customer_id) as count_no_trans 
from visits v
left join transactions t
ON t.visit_id = v.visit_id
WHERE transaction_id is NULL
GROUP BY customer_id
ORDER BY count_no_trans 