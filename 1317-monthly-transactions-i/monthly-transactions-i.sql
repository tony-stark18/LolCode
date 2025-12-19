-- Write your PostgreSQL query statement below
SELECT  to_char(t.trans_date,'YYYY-MM') as month,
        t.country,
        count(*) as trans_count,
        COALESCE(count(CASE WHEN t.state = 'approved' THEN 1 END),0) as approved_count,
        sum(t.amount) as trans_total_amount,
        COALESCE(sum(CASE WHEN t.state = 'approved' THEN t.amount END),0) as approved_total_amount
  FROM Transactions t
  GROUP BY 1,2