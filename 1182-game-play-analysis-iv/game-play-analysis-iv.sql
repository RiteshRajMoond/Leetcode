with first as (
    select player_id, min(event_date) as f_login
    from activity
    group by player_id
),
second as (
    select f.player_id from first f
    join activity a on f.player_id = a.player_id and datediff(a.event_date, f.f_login) = 1
)

select round((select count(player_id) from second) * 1.0/ (select count(distinct player_id) from activity),2) as fraction
;