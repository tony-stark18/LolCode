-- Write your PostgreSQL query statement below
SELECT t.teacher_id, COUNT(DISTINCT t.subject_id) as cnt
FROM Teacher t
GROUP BY 1