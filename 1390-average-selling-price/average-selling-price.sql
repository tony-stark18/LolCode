-- Write your PostgreSQL query statement below
SELECT P.product_id,COALESCE(ROUND((SUM(P.price * U.units)::float/SUM(U.units)::float)::numeric,2),0) as average_price FROM Prices P
LEFT JOIN UnitsSold U
ON P.product_id = U.product_id
AND U.purchase_date BETWEEN P.start_date AND P.end_date
GROUP BY 1;