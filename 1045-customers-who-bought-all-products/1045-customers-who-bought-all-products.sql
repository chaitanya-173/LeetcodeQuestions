# Write your MySQL query statement below
select customer_id
from Customer
group by Customer_id
having count(distinct product_key) = (
    select count(product_key) from Product
);