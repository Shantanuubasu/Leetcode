select customer_number from Orders
Group by customer_number
order by count(order_number) desc
limit 1

------------------------------------------------------------------------------
-- 1. We select customer number from orders table.
-- 2. Then we group customer_number together and in form of the most number of orders at top.
-- 3. Then we limit to display only one row.
