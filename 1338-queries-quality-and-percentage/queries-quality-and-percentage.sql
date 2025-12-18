-- Write your PostgreSQL query statement below
SELECT  q.query_name,
        ROUND(AVG(q.rating*1.00/q.position),2) as quality,
        ROUND((count(*) FILTER (WHERE q.rating<3))*100.00/count(*),2) as poor_query_percentage
FROM Queries q GROUP BY 1