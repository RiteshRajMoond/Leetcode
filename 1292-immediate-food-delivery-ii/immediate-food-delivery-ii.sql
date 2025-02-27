# Write your MySQL query statement below

SELECT
    ROUND(AVG(d.order_date = d.customer_pref_delivery_date)*100, 2) as immediate_percentage
from
    delivery d
WHERE
    (d.customer_id, d.order_date) in (
        SELECT
            d.customer_id,
            MIN(d.order_date)
            FROM
                delivery d
            GROUP BY
                d.customer_id
    )
;