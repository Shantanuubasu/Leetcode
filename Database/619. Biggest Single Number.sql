-- Write your MySQL query statement below
select MAX(num) as num from
(select num from MyNumbers 
group by num
having count(*)=1) as singlenum

----------------------------------------------------------
-- 1. We find the maximum number from a group of number having count as 1.
