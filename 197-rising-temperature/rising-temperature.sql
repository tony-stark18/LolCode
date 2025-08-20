-- Write your PostgreSQL query statement below
select w2.id as Id from Weather w1 cross join Weather w2 where w2.recorddate - w1.recorddate = 1 and w2.temperature > w1.temperature;