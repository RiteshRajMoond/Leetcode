# Write your MySQL query statement below

SELECT 
    q.query_name,
    ROUND(SUM(q.rating / q.position) / COUNT(q.query_name), 2) as quality,
    ROUND(SUM(q.rating < 3) * 100 / COUNT(q.query_name), 2) as poor_query_percentage
FROM
    queries q
GROUP BY
    q.query_name
;