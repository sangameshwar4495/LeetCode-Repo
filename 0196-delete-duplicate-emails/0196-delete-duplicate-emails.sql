# Write your MySQL query statement below
DELETE a
FROM Person a
JOIN person b
on a.email=b.email
and a.id>b.id;