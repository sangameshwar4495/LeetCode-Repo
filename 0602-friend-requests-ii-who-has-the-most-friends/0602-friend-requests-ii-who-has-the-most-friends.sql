with friends as(
    SELECT requester_id, accepter_id
    from requestAccepted

    union 

    select accepter_id, requester_id
    from requestAccepted
)

select requester_id as id, count(*) as num
from friends
group by requester_id
order by count(*) desc limit 1
