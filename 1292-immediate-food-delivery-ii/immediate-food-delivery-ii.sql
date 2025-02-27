# Write your MySQL query statement below

SELECT 
    ROUND(AVG(d.order_date = d.customer_pref_delivery_date)*100, 2) as immediate_percentage
FROM
    delivery d
WHERE
    (d.order_date, d.customer_id) IN (
        SELECT 
            MIN(d.order_date),
            d.customer_id
        FROM
            delivery d
        GROUP BY
            d.customer_id
    )
;