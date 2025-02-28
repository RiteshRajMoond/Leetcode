with firstlogin as (
    select player_id, min(event_date) as first_login
    from activity
    group by player_id
),
secondlogin as (
    select distinct a.player_id
    from activity a
    join firstlogin f
    on a.player_id = f.player_id
    where DATEDIFF(a.event_date, f.first_login) = 1
)

select round(
    (select count(player_id) from secondlogin) * 1.0 /
    (select count(distinct player_id) from activity)
    , 2) as fraction;