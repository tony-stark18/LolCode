-- Write your MySQL query statement below
WITH del_agg AS (
    SELECT d.customer_id,MIN(d.order_date) as od,
    MIN(d.customer_pref_delivery_date) as dd
    FROM Delivery d
    GROUP BY 1
)
select ROUND(SUM(CASE WHEN da.od = da.dd THEN 1 END)*100.00/COUNT(*),2) as immediate_percentage
from del_agg da;