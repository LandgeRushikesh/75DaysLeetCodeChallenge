# Write your MySQL query statement below
SELECT player_id,event_date AS 'first_login'
FROM Activity a1
WHERE a1.event_date = (
    SELECT a2.event_date
    FROM Activity a2
    WHERE a1.player_id = a2.player_id
    ORDER BY a2.event_date
    LIMIT 1
);