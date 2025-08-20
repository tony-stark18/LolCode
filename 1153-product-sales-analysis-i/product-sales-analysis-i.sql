-- Write your PostgreSQL query statement below
select b.product_name,a.year,a.price from sales a inner join product b using(product_id);