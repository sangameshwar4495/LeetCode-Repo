# Write your MySQL query statement below
DELETE a
FROM Person a
LEFT JOIN person b
on a.email=b.email
where a.id>b.id