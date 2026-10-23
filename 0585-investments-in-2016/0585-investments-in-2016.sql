# Write your MySQL query statement below
SELECT ROUND(sum(tiv_2016),2) as tiv_2016
from Insurance a
where 
    (select count(tiv_2015) from Insurance b where a.tiv_2015=b.tiv_2015)!=1
    AND
    (SELECT count(*) from Insurance b where a.lat=b.lat and a.lon=b.lon)=1