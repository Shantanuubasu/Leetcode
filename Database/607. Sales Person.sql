-- Write your MySQL query statement below
select name from SalesPerson where sales_id not in
(select sales_id from orders where com_id in
(select com_id from company where name='RED'))

----------------------------------------------------------------------------
/* 1. First we take name from salesperson whose sales id are not in the orders where com id is not of RED. */
