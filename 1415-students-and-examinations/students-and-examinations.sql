# Write your MySQL query statement below

SELECT
    st.student_id,
    st.student_name,
    sb.subject_name,
    COUNT(e.student_id) as attended_exams
FROM students st
CROSS JOIN subjects sb
LEFT JOIN examinations e
    ON st.student_id = e.student_id
    AND e.subject_name = sb.subject_name
GROUP BY
    1, 3
ORDER BY
    1 ASC
;