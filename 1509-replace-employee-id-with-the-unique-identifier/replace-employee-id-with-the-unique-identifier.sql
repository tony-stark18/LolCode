-- Write your PostgreSQL query statement below
select b.unique_id, a.name from Employees a left join EmployeeUNI b using(id);