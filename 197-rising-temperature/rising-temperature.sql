-- Write your PostgreSQL query statement below
select 
w2.id as Id from Weather w1 
join Weather w2 
on w2.recorddate - w1.recorddate = 1
where w2.temperature > w1.temperature;

-- select * from Weather w1 inner join Weather w2 on w1.temperature+w2.temperature > 50;