# Write your MySQL query statement below

SELECT 
    s.student_id,
    s.student_name, 
    su.subject_name, 
    COUNT(e.student_id) as attended_exams
FROM students s
CROSS JOIN subjects su
LEFT JOIN  examinations e
    ON s.student_id = e.student_id
    AND e.subject_name = su.subject_name
GROUP BY s.student_id, su.subject_name, s.student_name
ORDER BY s.student_id ASC
;