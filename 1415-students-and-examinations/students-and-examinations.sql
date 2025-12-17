-- Write your PostgreSQL query statement below
with exams_per_student as(
    select e.student_id as student_id,e.subject_name as subject_name,count(*) as attended_exams from Examinations e
    group by 1,2
),
students_with_exams as(
    select * from students s cross join subjects
    order by s.student_id,subject_name asc
)
select swe.*,COALESCE(eps.attended_exams, 0) as attended_exams
from students_with_exams as swe
left join exams_per_student as eps
on eps.student_id = swe.student_id
and eps.subject_name = swe.subject_name