-- Write your PostgreSQL query statement below
WITH activity_with_initial_login AS(
    SELECT a.player_id,MIN(a.event_date) as event_date
    FROM Activity a
    GROUP BY 1
) 
SELECT 
    ROUND(COUNT(DISTINCT a.player_id)*1.00/(SELECT COUNT(DISTINCT c.player_id) FROM Activity c),2) as fraction
    FROM Activity a
    JOIN activity_with_initial_login b
    ON a.event_date - b.event_date = 1 
    and a.player_id = b.player_id