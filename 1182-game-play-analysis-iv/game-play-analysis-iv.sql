SELECT
    ROUND(
        COUNT(*)*1.00
        / (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM (
    SELECT player_id
    FROM Activity
    GROUP BY player_id
    HAVING MIN(event_date) + 1 IN (
        SELECT event_date
        FROM Activity a2
        WHERE a2.player_id = Activity.player_id
    )
) t;
