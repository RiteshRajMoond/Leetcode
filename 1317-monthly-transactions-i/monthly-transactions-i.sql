# Write your MySQL query statement below

SELECT
    DATE_FORMAT(t.trans_date, "%Y-%m") AS month,
    t.country,
    COUNT(*) AS trans_count,
    SUM(t.state = "approved") AS approved_count,
    SUM(t.amount) as trans_total_amount,
    SUM(CASE WHEN t.state = "approved" THEN t.amount ELSE 0 END) AS approved_total_amount
FROM
    transactions t
GROUP BY
    month,
    t.country
;