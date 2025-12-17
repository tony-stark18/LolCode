-- Write your PostgreSQL query statement below
WITH manager_agg AS (
    SELECT managerId,count(*) AS majdurs
    FROM Employee e
    GROUP BY 1
)
SELECT e.name as name from manager_agg ma inner join Employee e
on ma.managerId = e.id
where ma.majdurs>=5