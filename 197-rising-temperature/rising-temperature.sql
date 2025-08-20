-- Write your PostgreSQL query statement below
select 
w2.id as Id from Weather w1 
join Weather w2 
on w2.recorddate - w1.recorddate = 1
where w2.temperature > w1.temperature;