-- Write your PostgreSQL query statement below
SELECT s.user_id,
    CASE 
        WHEN COUNT(c.action)>0 
            THEN round(((COUNT(CASE WHEN c.action = 'confirmed' THEN 1 END)::float)::numeric/(COUNT(c.action)::float)::numeric),2)
        ELSE 0
    END as confirmation_rate
FROM Signups s LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY 1