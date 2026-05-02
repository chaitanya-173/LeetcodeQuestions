# Write your MySQL query statement below
SELECT 
    ROUND(SUM(player_login) / COUNT(DISTINCT player_id), 2) AS fraction
FROM (
    SELECT 
        player_id,
        DATEDIFF(
            event_date,
            (
                SELECT MIN(event_date)
                FROM Activity a2
                WHERE a2.player_id = a1.player_id
            )
        ) = 1 AS player_login
    FROM Activity a1
) AS sub_table;

-- For each player:
-- Find first login date
-- Check if any login happened exactly one day later
-- Count such players
-- Divide by total players
