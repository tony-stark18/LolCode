-- Write your PostgreSQL query statement below
select  st.student_id as student_id,
        st.student_name as student_name,
        sb.subject_name as subject_name,
        count(ex.subject_name) as attended_exams
from students st cross join subjects sb
left join examinations ex
on ex.student_id = st.student_id
and ex.subject_name = sb.subject_name
group by 1,2,3
order by 1,3