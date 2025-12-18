-- Write your PostgreSQL query statement below
SELECT r.contest_id,
    ROUND((count(*)*100.00/(SELECT COUNT(DISTINCT user_id) AS cnt FROM  Users)),2) AS percentage
FROM Register r
GROUP BY 1
ORDER BY 2 DESC,
         1 ASC