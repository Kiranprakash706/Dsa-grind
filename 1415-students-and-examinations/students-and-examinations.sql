select s1.student_id,s1.student_name,s2.subject_name, count(s3.subject_name) as attended_exams
from Students s1
cross join Subjects s2
left join Examinations s3
on s1.student_id=s3.student_id
and s2.subject_name=s3.subject_name
group by s1.student_id, s1.student_name, s2.subject_name
order by s1.student_id, s2.subject_name


-- select s.student_id,s.Student_name,sub.subject_name, count(e.subject_name) as attended_exams
-- from Students s
-- cross join Subjects sub
-- left join Examinations e
-- on s.student_id=e.student_id 
-- and sub.subject_name=e.subject_name
-- group by s.student_id, s.student_name, sub.subject_name
-- order by s.student_id,sub.subject_name;